#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "KronaGramPlugin.h"

void KronaGramPlugin::input(std::string file) {
 inputfile = file;
 std::string singlefile;
    std::ifstream infile(file.c_str(), std::ios::in);
    while (!infile.eof()) {
       infile >> singlefile;
       if (singlefile != "" && !infile.eof())
       files.push_back(singlefile);
    }
 }

void KronaGramPlugin::run() {}

void KronaGramPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "ktImportText ";
 myCommand += "-o "+file; 
 for (int i = 0; i < files.size(); i++)
	myCommand += " "+std::string(PluginManager::prefix())+"/"+files[i];
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
    }

PluginProxy<KronaGramPlugin> KronaGramPluginProxy = PluginProxy<KronaGramPlugin>("KronaGram", PluginManager::getInstance());
