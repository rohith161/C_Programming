#include "stackImp.h"
#include <string.h>

// to check th whether the given expression has balanced brackets 
int evaluatexp(char* str){
  Stack* stack = initStack();
  int count  = 0;
  for(int i=0; str[i] != '\0'; i++){
    char ch = str[i];
    if( (ch == '(' || ch == '{' || ch == '[' || ch == ')' || ch == '}' || ch == ']') ){
        
        if( ch == '(' || ch == '{' || ch == '[' ){
            push(stack,ch);
            count++;
        }
        else if( ch == ')' || ch == '}' || ch == ']' ){
            char top = Top(stack);
            if(isEmpty && count == 0){
                printf("\n Wrong Format\n");
                clear(stack);
                return 0;
            }
            if ( (top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']') ) {
                pop(stack);
                count--;
                continue;
            }
            else{
                 printf("\n Wrong Format\n");
                clear(stack);
                return 0;
            }
        }
    }
    else{
        continue;
    }
  } 
  
    printf("\n%s\n",(isEmpty(stack) ? "Correct Format" : "Wrong Format"));
    int out = isEmpty(stack);
    clear(stack);
    return out;

}

// To assign the highest precendence according to the Operator
int priority(const char c){
    if(c == '*'){
      return 4;
    }
    else if(c == '/'){
      return 3;
    }
    else if(c == '+'){
      return 2;
    }
    else if(c == '-'){
      return 1;
    }
    else{
      return 0;
    }
}

// conversion of the gien expression in the postfix state for better machine understanding
char* postfix(char* s){
  Stack* stack = initStack();
  int size = strlen(s);
  char* res = (char*) malloc((size*2) * sizeof(char));
  int count = 0;
  for(int i=0; i<size; i++){
    char ch = s[i];
    if(ch == ' '){
      continue;
    }
    int precedence = priority(ch);
    if(ch == '('){
      push(stack,ch);
      continue;
    }

    else if(ch >= '0' && ch <= '9'){
      if(res[count-2] >= '0' && res[count-2] <= '9' && s[i-1] >= '0' && s[i-1] <= '9' ){
        res[count-1] = ch;
        res[count++] = ' ';
        continue;
      }
      res[count++] = ch;
      res[count++] = ' ';
      continue;
    }

    else if( Top(stack) == '('  || (precedence >= 1 && precedence <= 4) ){

      if(priority(Top(stack)) > precedence){
        while (!isEmpty(stack) && Top(stack) != '(')
        {
          res[count++] = pop(stack);
          res[count++] = ' ';
        }  
        push(stack,ch);
        continue;
      }
      if(precedence >= 1 && precedence <= 4){
      push(stack,ch);
      continue;
      }
    }
    else if( !isEmpty(stack) &&  (priority(Top(stack)) >= 1 &&  priority(Top(stack)) <= 4 ) && (precedence >= 1 && precedence <= 4) ){
      if(precedence > priority(Top(stack))){
        push(stack,s[i]);
        continue;
      }
      else{
      res[count++] = pop(stack);
      res[count++] = ' ';

      }
    }
    else if( !isEmpty(stack) &&  (ch == ')' || (priority(Top(stack)) >= 1 &&  priority(Top(stack)) <= 4 )) ){
      res[count++] = pop(stack);
      res[count++] = ' ';
      pop(stack);
    }

  }
  while(!isEmpty(stack)){
    if(Top(stack) == '(' || Top(stack) == ')' ){
      return "Inavlid Format";
    }
      res[count++] = pop(stack);
      res[count++] = ' ';
    }
  res[count] = '\0';

  clear(stack);
  return res;

}

// To perform the operator operation on the operands
void execute(Stack* st,int op1,int op2,const char* token){
  if(*token == '*'){
    push(st,(op1 * op2));
    return;
  }
  else if(*token == '/'){
    push(st,(op1 / op2));
    return;
  }
  else if(*token == '+'){
    push(st,(op1 + op2));
    return;
  }
  else if(*token == '-'){
    push(st,(op1 - op2));
    return;
  }
  else{
    return;
    }
}

// Function which calculates the given expression
int calculation(char* s){
  int out = 0;
  char* postfix_exp = postfix(s);
  printf("\n%s\n", postfix_exp);
  Stack* st = initStack();
  char* token =  strtok(postfix_exp," ");
  while (token != NULL)
  {
    if(*token == '*' || *token == '/' || *token == '+' || *token == '-' ){
      int op2 = pop(st);
      int op1 = pop(st);
      execute(st,op1,op2,token);
    }

    else{
      push(st,atoi(token));
    }
    
    token = strtok(NULL," ");
  }

  out = pop(st);
  clear(st);
  return out;
}

int main(){
    char str[] = "{[(12)(14)]}";


    char infix[] = "{[(1123+25)*14]/73}  ";    // (((1123+25)*14)/73)    1123+25*14/73 

    evaluatexp(infix);

    int out = calculation(infix);
    printf("\n%d\n", out);
    return 0;
}