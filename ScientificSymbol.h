#pragma once

enum SymbolType {
 compass,quill,wheel,tablet,scale,bowl,globe 
};

class ScientificSymbol { 
private : 
	SymbolType type; 
	int count;
	void add();
	ScientificSymbol(SymbolType t, int c = 0); 
	
};