#include <boost/program_options.hpp>

#include <iostream>

using boost::program_options::notify;
using boost::program_options::options_description;
using boost::program_options::parse_command_line;
using boost::program_options::store;
using boost::program_options::value;
using boost::program_options::variables_map;
using std::cout;

int main(int    argc,
         char * argv[]
         ) {
	options_description desc( "Allowed options" );
	desc.add_options()
		( "help",        "produce help message"                )
		( "compression", value<int>(), "set compression level" );

	variables_map vm;
	store( parse_command_line( argc, argv, desc), vm );
	notify( vm );

	if ( vm.count( "help" ) ) {
		cout << desc << "\n";
		return 1;
	}

	if (vm.count("compression")) {
		cout
			<< "Compression level was set to " 
			<< vm["compression"].as<int>()
			<< ".\n";
	}
	else {
		cout << "Compression level was not set.\n"
			<< "   "      << __DATE__<< " "<< __TIME__<< "\n"
			<< "   "      << BOOST_COMPILER           << "\n"
			<< "   "      << BOOST_STDLIB             << "\n"
			<< "   Boost "<< BOOST_LIB_VERSION        << "\n";
	}

	return 0;
}
