#include <iostream>
#include <fstream>
#include <string>

int	return_error(std::string message)
{
	std::cout << message << "\n";
	exit (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return_error("Use: ./mysed <filename> <s1> <s2>");

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
		return_error("String to replace cannot be empty");

	std::ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
		return_error("Failed to open file: " + filename);

	std::ofstream outfile;
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
		return_error("Failed to open file: " + filename + ".replace");

	std::string line;
	size_t		pos;
	while (infile.good())
	{
		std::getline(infile, line);
		if ((infile.rdstate() & std::ios_base::badbit) != 0)
			return_error("Read failed");
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		if ((infile.rdstate() & std::ios_base::eofbit) != 0)
			outfile << line;
		else
			outfile << line << "\n";
	}
}