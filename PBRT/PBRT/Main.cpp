#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	Options options;
	vector<string> filenames;

	pbrtInit(options);

	if (filenames.size() == 0)
	{
		ParseFile("-");
	}
	else
	{
		for (u_int i = 0; i < filenames.size(); i++)
		{
			if (!ParseFile(filenames[i]))
				Error("Nao foi possivel abrir o arquivo de cena \"%s\"", filenames[i].c_str());
		}
	}

	pbrtCleanup();
	return 0;
}