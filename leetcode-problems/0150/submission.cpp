class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<int> stack;
        
        for(int i=0; i<tokens.size(); i++){
            
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                int a = stack.back();
                stack.pop_back();
                int b = stack.back();
                stack.pop_back();
                char c = tokens[i][0];
                
                switch(c){
                    case '+':
                        stack.push_back(b+a); break;
                    case '-':
                        stack.push_back(b-a); break;
                    case '*':
                        stack.push_back(b*a); break;
                    case '/':
                        stack.push_back(b/a); break;
                }
            } else{
                
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack[0];
    }
};
