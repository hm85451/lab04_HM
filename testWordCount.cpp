#include<iostream>
#include"WordCount.h"
#include"tddFuncs.h"

using namespace std;

int main()
{
    cout<<"testing functions for empty cases d1"<<endl;
    WordCount d1;
    ASSERT_EQUALS(0,d1.getTotalWords());
    ASSERT_EQUALS(0,d1.getNumUniqueWords());
    ASSERT_EQUALS(0,d1.getWordCount("apple"));

    cout<<endl;

    cout<<"testing functions for d2"<<endl;
    WordCount d2;
    d2.incrWordCount("appl*#e");
    d2.incrWordCount("apple");
    ASSERT_EQUALS(2,d2.getTotalWords());
    ASSERT_EQUALS(1,d2.getNumUniqueWords());
    ASSERT_EQUALS(2,d2.getWordCount("apple"));
    ASSERT_EQUALS(0,d2.getWordCount("banana"));
    
    cout<<endl;

    cout<<"testing functions for d3"<<endl;
    WordCount d3;
    d3.incrWordCount("good");
    d3.incrWordCount("hello");
    d3.incrWordCount("world");
    d3.incrWordCount("good");
    ASSERT_EQUALS(4,d3.getTotalWords());
    ASSERT_EQUALS(3,d3.getNumUniqueWords());
    ASSERT_EQUALS(1,d3.getWordCount("world"));
    ASSERT_EQUALS(0,d3.getWordCount("sky"));
    ASSERT_EQUALS(2,d3.getWordCount("good"));
   
    cout<<endl;

    cout<<"testing stripWord function"<<endl;
    ASSERT_EQUALS("Jacky", WordCount::stripWord("Jacky"));
    ASSERT_EQUALS("Jacky", WordCount::stripWord("'Jacky--"));
    ASSERT_EQUALS("", WordCount::stripWord("---"));
    ASSERT_EQUALS("watermelon", WordCount::stripWord("!watermel@#on"));
    ASSERT_EQUALS("good-heartedcan't", WordCount::stripWord("good-heartedcan't"));
    return 0;
}
