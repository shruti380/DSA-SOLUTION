class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
    }
    
    bool isConsonant(char ch){
        // Check if it's an alphabetic character AND not a vowel
        return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) && !isVowel(ch);
    }
    
    bool isDigit(char ch){
        return (ch>='0'&&ch<='9');
    }
    
    bool isValidChar(char ch){
        // Only digits and English letters are valid
        return isDigit(ch) || (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z');
    }

    bool isValid(string word) {
        int n = word.size();
        
        // Check minimum length
        if(n < 3){
            return false;
        }
        
        bool hasVowel = false;
        bool hasConsonant = false;
        
        for(int i = 0; i < n; i++){
            // Check if character is valid (only digits and English letters allowed)
            if(!isValidChar(word[i])){
                return false;
            }
            
            if(isVowel(word[i])){
                hasVowel = true;
            }
            
            if(isConsonant(word[i])){
                hasConsonant = true;
            }
        }
        
        return hasVowel && hasConsonant;
    }
};