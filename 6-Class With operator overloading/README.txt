Q 1) explain why you chose to represent the Money amount the way you did:
why did you choose 2 integers? Or why did you use a double? Or an integer?
what were the advantages vs disadvantages of your choice
ANS:  I used int dollar and int cent:
        Advantages:
             can easily access the dollar and cent using functions only;
             can modify the values easily using set functions:
             easy to declare and use
      Disadvantages:
          Each time the money is needed to be calculated by using both values
           sometime confusion as the money contains the cent values after decimal point but
           cent is itself is integer,

Q 2)
     Bonus:
 Ans: I did the bonus part
   1)   (-) unary operator , I simply change the values to opposite sign ;
   2) a)  ( /) binary operator for division
           I write a function that divide the given money into n people as required.
              I tried to divide the total money by n
       b) explain the division/operator: how does it relate to multiplication?
          ans: Lets take an example:
                 if m=10;
                    n=3;
                    than divide m\n=10\3=3.33 but 3.33*3=9.9
                     Here is loss of small dollar but it moslty happen when m is not properly divisible among n;
              but if m=9;
                  n=3;
              than divide=9\3=3   and multilply also 3*3=9;
               So here it is equal .
         So we can say that if money is equally dividable among n ,then all be get exactly same ratio,
             otherwise it can be a small different;
    c)How did you divide $1 Money by 3 people?
      ans: if we will try to divide :
                   1/3=0.33
Here again it is not properly divided.So each person will get 0.33 dollars.

3) code the function “get dollars” so that it rounds off (rounds up) the half cent i.e. 7.995 will return 8

Ans: In the file I have added the code .It rounds up the value  as it was the requirement.

4)tests for the bonus part
ans: All the test cases are in unittest file 
