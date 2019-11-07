// WordCount.cpp
#include<algorithm>
#include "WordCount.h"
#include<vector>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
    int count = 0;
    for (size_t i = 0;i< CAPACITY; i++)
    {
        if (table[i].size()!=0)
        {
            for(size_t j = 0; j < table[i].size(); j++)
            {
                count += (int)table[i][j].second;
            }
        }
    }
	return count;
}

int WordCount::getNumUniqueWords() const {
	int count = 0;
    for (size_t i = 0; i < CAPACITY; i++)
    {
        count+= table[i].size();
    }
	return count;
}

int WordCount::getWordCount(std::string word) const {
    word = stripWord(word);
    transform(word.begin(),word.end(),word.begin(),::toupper);
	size_t hashIndex = hash(word);
    for (size_t i = 0; i < table[hashIndex].size(); i++)
    {
        if (table[hashIndex][i].first==word)
            return  table[hashIndex][i].second;
    }
    
	return 0;
}
	

int WordCount::incrWordCount(std::string word) {
	word = stripWord(word);
    if (word.length()==0)
        return 0;
    transform(word.begin(),word.end(),word.begin(),::toupper);
    size_t hashIndex = hash(word);
    for (size_t i = 0;i < table[hashIndex].size(); i++)
    {
        if (table[hashIndex][i].first == word)
            return ++table[hashIndex][i].second;
    }
    table[hashIndex].push_back(pair<string,size_t>(word,1));
    return 1;
}


bool WordCount::isWordChar(char c) {
	if ((c>=97&&c<=122)||(c>=65&&c<=90))
	    return true;
    return false;
}


std::string WordCount::stripWord(std::string word) {
	string word2 = "";
    for (size_t i = 0; i < word.size();i++)
    {
        if (isWordChar(word[i]))
            word2+=word[i];
        if (word[i]=='-'||word[i]=='\'')
            if (word2.length()!=0)
                word2+=word[i];
    }
    while(word2.length()>0 && (!isWordChar(word2[word2.length()-1])))
    {
        word2 = word2.substr(0,word2.length()-1);
    }
	return word2;
}
