double sqroot(int val);

struct Result {
   double spentTime;
   double sqr;
};

struct Result TimeDecorator( double (*func)(int ), int val ); 