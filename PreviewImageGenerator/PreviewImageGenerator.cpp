// LFInteractive LLC. (c) 2020-2024 All Rights Reserved
#include <iostream>
#include <filesystem>
using namespace std::filesystem;

int main(int argc, char** argv)
{
	try
	{
		path currentDir = current_path();
		for (auto& file : directory_iterator(currentDir))
		{
			if (file.path().extension() == ".png" ||
				file.path().extension() == ".jpg" ||
				file.path().extension() == ".jpeg")
			{
				auto new_name = file.path().stem().string() + "_sm" + file.path().extension().string();

				std::filesystem::create_directory("small");

				// run ffmpeg command on every file
				std::string command = "ffmpeg -y -i \"" + file.path().string() + "\" -vf scale=-1:20 \"small/" + new_name + "\"";
				std::system(command.c_str());
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return 1;
	}

	return 0;
}