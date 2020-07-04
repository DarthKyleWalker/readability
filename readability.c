#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void){
    string text = get_string("Text: \n");
    float L = count_letters(text) * 100 / (float)count_words(text);
    float S = count_sentences(text) * 100 /(float) count_words(text); 
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    if(index<1){
        printf("Before Grade 1\n");
    }
    else if(index >=16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %.0f\n", round(index) );
    }
}

int count_letters(string text){
    int letters = 0;

    for(int i=0,n=strlen(text);i<n;i++){
        if(text[i]>= 'a' && text[i]<= 'z'){
            letters += 1;
        }
        else if(text[i] >='A' && text[i] <='Z'){
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text){
    int words = 1;

    for(int i=0,n = strlen(text); i<n;i++){
        if(text[i]== ' '){
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text){
    int sentences = 0;
    
    for(int i=0,n = strlen(text);i<n;i++){
        if(text[i]=='.' || text[i]=='?' || text[i]=='!'){
            sentences += 1;
        }
    }
    return sentences;
}
