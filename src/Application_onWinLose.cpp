#include "Application.h"
#include <fstream>

void Application::onWin()
{
	std::ofstream fout;
	fout.open("award.txt");

	fout << "Abraham Lincoln Hunter: Typing Simulator Award" << std::endl;
	fout << "==============================================" << std::endl;
	fout << "First Place Award for Excellence in the Field  " << std::endl;
	fout << "of Meta-Typing:" << std::endl;
	fout << "  You are officially so meta" << std::endl;
	fout << "  that you win the IM Award." << std::endl;
	fout << "  It stands for: " << std::endl;
	fout << "    IM Meta" << std::endl;

	fout.close();
}
void Application::onLose()
{
	std::ofstream fout;
	fout.open("award.txt");

	fout << "Abraham Lincoln Hunter: Typing Simulator Award" << std::endl;
	fout << "===============================================" << std::endl;
	fout << "First Place Award for Failing in the Field  " << std::endl;
	fout << "of Meta-Typing:" << std::endl; 
	fout << "  You are now officially worse than Hitler." << std::endl;
	fout << "  How could you." << std::endl;
	fout << "  YOU ARE TEARING ME APART!" << std::endl;

	fout.close();
}
