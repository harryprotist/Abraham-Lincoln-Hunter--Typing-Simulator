#include "Application.h"

void Application::onLoop()
{
	SDL_Delay(5);

	// Timer Stuff
	int curNumTicks = SDL_GetTicks();
	lastNumTicks = curNumTicks - prevTicks;

	countTicks += lastNumTicks;


	switch(gameState)	
	{
	case -1:
		onLoop_splash();
	break;
	case 0:
		onLoop_menu();
	break;
	case 1:
		onLoop_game();
	break;
	case 2:
		onLoop_type();
	break;
	default:break;
	}

	prevTicks = curNumTicks;
}

void Application::onLoop_splash()
{
	splashTime += lastNumTicks;

	if(splashTime > 4000)
		gameState = 0;
}

void Application::onLoop_game()
{
	int lHandSpeed = 3, rHandSpeed = 3;
	countTo30 += lastNumTicks;

	bool canMove = true;

	runPresses(lHandSpeed, rHandSpeed);

	if(!p_isMoving && !hasEntered)
	{
		if(runTyping()) // if the user has hit enter
		{
			// Enter text and check if match
			if(vIn.substr(0, vIn.length() - 1) == Words::getPhrase().substr(0, Words::getPhrase().length() - 1))
			{
				hasEntered = true;	
				vIn = "_";
				Words::setPhrase(" Enter the number of the direction you wish to move ");		
			}
			vIn = "_";
		}	
	}
	else if(hasEntered)
	{
		for(int i = 1; i < 5; i++)
		{
			if(!VKeys::getKey(i))
				keyDelay[i] = 0;
			else if(VKeys::getKey(i) && keyDelay[i] <= 0)
			{
				keyDelay[i] = 400;

				switch(i)
				{
				case 1:	canMove = !(player->currentRoom->up == player->currentRoom); break;
				case 2: canMove = !(player->currentRoom->right == player->currentRoom); break;
				case 3: canMove = !(player->currentRoom->down == player->currentRoom); break;
				case 4: canMove = !(player->currentRoom->left == player->currentRoom); break;
				}

				if(canMove)
				{
					player->moveRoom(i - 1);
					player->image.state = i - 1;
					hasEntered = false;
					p_isMoving = true;

					Words::setPhrase( " " );
				}
			}
			else if(keyDelay[i] > 0)
				keyDelay[i] -= lastNumTicks;
		}		
	}
	else if(p_isMoving)
	{
		lHandSpeed = 0;	
		rHandSpeed = 0;

		if(!player->onLoop())
		{
			p_isMoving = false;
			Words::scrambleWords();
			player->image.state = 4;
		}
	}

	runHandMove(lHandSpeed, rHandSpeed);
	
	// Lincoln's Movememt
	if(countTo30 >= 30000 && !l_isMoving)
	{
		countTo30 = 0; // reset timer
		l_isMoving = true;

		int l_dir = lincoln->onCalc();			

		lincoln->image.state = l_dir; 
		lincoln->moveRoom(l_dir);
	}
	else if(l_isMoving)
	{
		countTo30 = 0;
		if(!lincoln->onLoop())
		{
			l_isMoving = false;
			lincoln->image.state = 4;
		}
	}
	
	if (fabs(lincoln->x - player->x) <= 0.05f && fabs(lincoln->y - player->y) <= 0.5f)
	{
		// to any transition code here
		cacheText();
		vIn = "_";
		gameState = 2;		
	}
}

void Application::onLoop_menu()
{
}

void Application::onLoop_type()
{	
	// lincoln's typing
	countTo2 += lastNumTicks;
	if (countTo2 > 2000)
	{	
		lincolnProgress++;
		countTo2 = 0;
	}	
	gameLost = (lincolnProgress >= 764);

	// hand movement and typing
	int lHandSpeed = 3, rHandSpeed = 3;
	runPresses(lHandSpeed, rHandSpeed);

	if (runTyping() ) // if the enter key has been pressed
	{
		vIn = vIn.substr(0, vIn.length() - 1);
		if (vIn == address.at(currentLine) )
		{
			currentLine++;
			cacheText();
		}

		vIn = "_";
	}
	runHandMove(lHandSpeed, rHandSpeed);
	
	gameWon = (currentLine == address.size() );

	if (gameWon || gameLost) // replace with actual winning or losing
	{
		if (gameWon)
		{
			onWin();
		}
		else if (gameLost)
		{
			onLose();
		}
	
		running = false;
	}
}

bool Application::runTyping()
{
	for(int i = 0; i < 61; i++)
	{
		if(!VKeys::getKey(i))
			keyDelay[i] = 0;

		else if(VKeys::getKey(i) && keyDelay[i] <= 0)
		{
			keyDelay[i] = 400;
			if(VKeys::translateKey(i) == '>')
			{
				return true;
			}
			else if(VKeys::translateKey(i) == '<')
			{
				if(vIn.length() > 1)
				{
					vIn = vIn.substr(0, vIn.length() - 1);
					vIn.erase(vIn.length() - 1);
					vIn += '_';
				}
			}
			else if(VKeys::translateKey(i) != '|' && vIn.length() < 54)
			{
				vIn = vIn.substr(0, vIn.length() - 1);
				vIn += VKeys::translateKey(i);
				vIn += '_';
			}
		}
		else if(keyDelay[i] > 0)
			keyDelay[i] -= lastNumTicks;
	}
	return false;
}
void Application::runPresses(int& lHandSpeed, int& rHandSpeed)
{
	// Finger pressing
	if(keys[SDLK_1])
		lHandSpeed = 0;
	else if(keys[SDLK_2])
		lHandSpeed = 0;
	else if(keys[SDLK_3])	
		lHandSpeed = 0;
	else if(keys[SDLK_4])
		lHandSpeed = 0;
	else if(keys[SDLK_5])
		lHandSpeed = 0;
	else if(keys[SDLK_6])
		rHandSpeed = 0;
	else if(keys[SDLK_7])
		rHandSpeed = 0;
	else if(keys[SDLK_8])
		rHandSpeed = 0;
	else if(keys[SDLK_9])
		rHandSpeed = 0;
	else if(keys[SDLK_0])
		rHandSpeed = 0;

	lHand->fingers[0] = keys[SDLK_1];
	lHand->fingers[1] = keys[SDLK_2];
	lHand->fingers[2] = keys[SDLK_3];
	lHand->fingers[3] = keys[SDLK_4];
	lHand->fingers[4] = keys[SDLK_5];
	rHand->fingers[0] = keys[SDLK_6];
	rHand->fingers[1] = keys[SDLK_7];
	rHand->fingers[2] = keys[SDLK_8];
	rHand->fingers[3] = keys[SDLK_9];
	rHand->fingers[4] = keys[SDLK_0];

	// Handle any virtual keypresses
	Hand::getKeyPress(lHand, rHand);
	
}
void Application::runHandMove(int lHandSpeed, int rHandSpeed)
{
	// Left Hand movement
	if(keys[SDLK_w] && lHand->y > 365)
		lHand->y -= lHandSpeed;
	if(keys[SDLK_a] && lHand->x > -100)
		lHand->x -= lHandSpeed;
	if(keys[SDLK_s] && lHand->y < 600)
		lHand->y += lHandSpeed;
	if(keys[SDLK_d] && lHand->x < 700)
		lHand->x += lHandSpeed;

	// Right Hand movement
	if(keys[SDLK_i] && rHand->y > 365)
		rHand->y -= rHandSpeed;
	if(keys[SDLK_j] && rHand->x > -100)
		rHand->x -= rHandSpeed;
	if(keys[SDLK_k] && rHand->y < 600)
		rHand->y += rHandSpeed;
	if(keys[SDLK_l] && rHand->x < 700)
		rHand->x += rHandSpeed;

}

void Application::cacheText()
{
	Render::Blit(paper_original, paper, 0, 0);
	for (int i = currentLine, n = 0; i < address.size(); i++)
	{
		Render::DrawText(aFont, paper, address.at(i).c_str(), 125, (n * 20) + 80);	
		n++;
	}
}
