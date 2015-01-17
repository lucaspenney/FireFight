#include "Application.h"
#include <iostream>
#include <boost/program_options.hpp>
namespace po = boost::program_options;
int main(int argc, char* argv[])
{
	po::options_description desc("Allowed options");
	desc.add_options()
	("help,h", "Display this help message")
    ("server,s", "Server");
	
	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
	po::notify(vm);
	
	if (vm.count("help")) {
		std::cout << "Looks like you need help." << std::endl;
	}
	
	//Launch with server
	if (vm.count("server")) {
		
	}
	Application game;
	return 0;
}