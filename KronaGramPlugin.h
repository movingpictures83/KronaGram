#ifndef KRONAGRAMPLUGIN_H
#define KRONAGRAMPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class KronaGramPlugin : public Plugin
{
public: 
 std::string toString() {return "KronaGram";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> files;
};

#endif
