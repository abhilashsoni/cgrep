#include <iostream>
#include <regex>
#include <bits/stdc++.h>

using namespace std;

int main(int args, char** argv)
{
	int offset=0, v=0, i=0, w=0, n=0, x=0, lineno=0;
	if(args==4)
	{
		offset = 1;
		string temp = argv[1];
		for(int j=1; j<temp.length(); j++) 
		{
			if(argv[1][j]=='v') v=1;
			else if(argv[1][j]=='i') i=1;
			else if(argv[1][j]=='w') w=1;
			else if(argv[1][j]=='n') n=1;
			else x=1;
		}
	}
	string pattern = argv[offset+1];
	if(i) transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
	if(w) 
	{
		pattern += "\\b";
		pattern.insert(0, "\\b");
	}
	regex r(pattern);

	ifstream fin;
	fin.open(argv[offset+2]);
	
	smatch m;
	for(string line; getline(fin, line);)
	{
		lineno++;
		string k = line;
		transform(k.begin(), k.end(), k.begin(), ::tolower);
		if(i) 
		{
			if(!v && regex_search(k, m, r))
			{
				if(n) cout<<lineno<<"\t";
				cout<<line<<"\n";
			}
			else if(v && !regex_search(k, m, r))
			{
				if(n) cout<<lineno<<"\t";
				cout<<line<<"\n";
			}
		}	
		else
		{
			if(!v && regex_search(line, m, r)) 
			{
				if(n) cout<<lineno<<"\t";
				cout<<line<<"\n";
			}
			else if(v && !regex_search(line, m, r))
			{
				if(n) cout<<lineno<<"\t";
				cout<<line<<"\n";
			}
		}
	}
	fin.close();
	return 0;
}
