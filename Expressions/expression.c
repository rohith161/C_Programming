#include "stackImp.h"
#include <string.h>

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
    int out = (isEmpty(stack)) ? 1 : 0;
    clear(stack);
    return out;

}

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


char* postfix(char* s){
  if(evaluatexp(s) == 1){
  Stack* stack = initStack();
  int size = strlen(s);
  char* res = (char*) malloc((size*2) * sizeof(char));
  int count = 0;
  for(int i=0; i<size; i++){
    if(s[i] == ' '){
      continue;
    }
   // printf("%c ",Top(stack));
    int precedence = priority(s[i]);
    if(s[i] == '('){
      push(stack,s[i]);
      continue;
    }

    else if(s[i] >= '0' && s[i] <= '9'){
      if(res[count-2] >= '0' && res[count-2] <= '9' && s[i-1] >= '0' && s[i-1] <= '9' ){
        res[count-1] = s[i];
        res[count++] = ' ';
        continue;
      }
      res[count++] = s[i];
      res[count++] = ' ';
      continue;
    }

    else if( (Top(stack) == '('  || (precedence >= 1 && precedence <= 4) )){

      if(priority(Top(stack)) > precedence && precedence != 0){
        while(!isEmpty){
          res[count++] = pop(stack);
          res[count++] = ' ';
        }
        push(stack,s[i]);
        continue;
      }
      if(precedence >= 1 && precedence <= 4){
      push(stack,s[i]);
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
    else if( !isEmpty(stack) &&  (s[i] == ')' || (priority(Top(stack)) >= 1 &&  priority(Top(stack)) <= 4 )) ){
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
  else{
    return "Invalid format";
  }

}

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

int calculation(char* s){
   if(evaluatexp(s) == 0){
    printf("\n Invalid Format\n");
    return -1;
  }
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


    char infix[] = "1123+25*14/73";    // (((1123+25)*14)/73)    1123+25*14/73 

    evaluatexp(infix);

    int out = calculation(infix);
    printf("\n%d\n", out);
    return 0;
}