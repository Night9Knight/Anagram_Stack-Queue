#include <iostream>
#include <cstring>
#include <fstream>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
using namespace std;

int factorial (int num){
	int total = num;
	if (num == 0)
		return 1;
	else{
		for (int i = 1; i<num; i++){
			total = total * (num-i);
		}
	}
	return total;
}

//Number of occurrences for chosen character in a string
int countChar(string word, char a)
{
    int counts=0;
    for(int i=0; i<word.length(); i++)
    {
        if(word[i]==a)
            counts++;
    }
    return counts;
}

//Remove chosen character from the string
void removeChar(string &word, char a)
{
    string temp;
    for(int i=0;i<word.length();i++)
    {
        if(word[i]!=a)
            temp+=word[i];
    }
    word=temp;
}

//Count possible number of anagram for the word
int num_of_anagram(string word){
     int num = factorial(word.length());
     while(word.length()!=0)
     {
         num= num/factorial(countChar(word,word[0]));
         removeChar(word,word[0]);
     }
     return num;
}

class Anag{
	private:
//		queue <char> Q;
//		stack <char> S;
		string word;
	public:
		void setWord(string w){word = w;}
		string getWord(){return word;}
//		void generate();
		int getN(){return word.length();}
		Anag()
		{word="N/A";}
		Anag(string w)
		{
		    word = w;
		}
		~Anag()
		{word="N/A";}

};

/*void Anag::generate(){
//	int A,B;
//    int i=0;
//    string curr_word;
//    string new_word = " ";
//    int num;
//    char temp;
//    bool run=true;
//   int n = getWord().length();

    char char_array[getN()]; // declaring character array
    // copying the contents of the
    // string to char array
    strcpy(char_array, getWord().c_str());

    for (int i = 0; i < getN(); i++)
        Q.enQueue(char_array[i]);
}*/

int main()
{
	queue <char> Q;
	stack <char> S;
	LinkedList <Anag> anagram;
    string s;// assigning value to string s
    Anag anagramobj;

    int A,B;
    int j=0;
    string curr_word, new_word;
    int num;
    char temp;
    bool run=true;

	cout<<"Enter words: ";
	cin>>s;
	anagramobj.setWord(s);
	int word_length = s.length();
	anagram.appendNode(anagramobj);
//	anagramobj.generate();

/*    int n = s.length();
    cout<<"Length= "<<n<<endl;
    char char_array[anagramobj.getN()]; // declaring character array

    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str()); */

    for (int i = 0; i < anagramobj.getN(); i++)
        Q.enQueue(s[i]);

    A = word_length-1;
    curr_word = anagramobj.getWord();
    while(anagram.c()!=num_of_anagram(s)){//int
    	int B = A;
    	while(B != 0)
    	{
    		new_word ="";
    		for(int i=0; i<B; i++){
    		S.Push(Q.front());
    		Q.deQueue();
    		}


			while(!S.IsEmptyStack())
			{
				Q.enQueue(S.Top());
				S.Pop();
			}

	    	while(!Q.IsEmpty())
	    	{
	    		temp=Q.front();
	    		Q.deQueue();
	    		new_word+=temp;
			}

			for(int i=0; i<word_length; i++)
            {
                Q.enQueue(new_word[i]);
            }

		/*	if(anagram.searchNode(new_word)){
				run=false;
				break;
				}

			else
				run=true;*/
            anagramobj = Anag(new_word);

			if(!anagram.searchNode(anagramobj))
			{
				anagram.appendNode(anagramobj);
			}



	    	B=B-1;
    	}

		if(new_word==curr_word)
		A=A-1;

		if(A==0)
		{
			A=word_length-1;
			j=j+1;
			curr_word=anagram.anagramList(j);//int
			while(!Q.IsEmpty())
                Q.deQueue();
            for(int k=0; k<word_length; k++)
                Q.enQueue(curr_word[k]);
		}

	}

    cout<<"List of anagram for \""<<s<<"\": "<<endl;
	anagram.displayList();
	cout<<"Number of anagram: "<<anagram.c()<<endl;
	system("Pause");

    return 0;
}
