#include "Main.h"

/*
*****************************************************
*												 	*
*	Configparser by Saeurenmensch				 	*
*												 	*
*	pls credit me if you're going to use this ;-)	*
*												 	*
*****************************************************
*/


cConfig::cConfig()
{
	this->strConfigPath = ""; // Configpath leermachen da nichts übergeben wurde
}



cConfig::cConfig(std::string configpath, confParams configMode)
{
	//modus setzen
	this->e_confparams = configMode;

	this->strConfigPath = configpath; // strConfigPath auf den übergebenen path setzen

	// filestreams öffnen

	switch (this->e_confparams) // switch für die parameter
	{
	case CONFIG_READ: // nur lesen
		this->openInputStream();
		break;
	case CONFIG_WRITE: // nur schrieben
		this->openOutputStream();
		break;
	case CONFIG_READWRITE: //lesen und schreiben
		this->openInputStream();
		this->openOutputStream();
		break;
	default: // default wenn davon nix ist.
		break;
	}




}

cConfig::~cConfig() // schliest die streams
{
	//filestreams schließen
	this->closeInputStream();
	this->closeOutputStream();
}

std::string cConfig::getPath() // gibt den path der config zurück
{
	return this->strConfigPath; // returnt den strConfigPath
}

void cConfig::setParam(confParams Params)
{
	this->e_confparams = Params;
}

void FORCEINLINE cConfig::closeOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream.close();
	}
}


void FORCEINLINE cConfig::closeInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream.close();
	}
}

void FORCEINLINE cConfig::openOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream = std::ofstream(this->strConfigPath, std::ios::out); // outputstream öffnen
	}
}

void FORCEINLINE cConfig::openInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream = std::ifstream(this->strConfigPath, std::ios::in); // inputstream öffnen
	}
}
