#include <iostream>
using namespace std;

int a1[12],
    a2[12],
    a3[12];
char einStr[]    = "Enter integer #";
char moStr[]     = "Max of ";
char ieStr[]     = " ints entered...";
char emiStr[]    = "Enter more ints? (n or N = no, others = yes) ";
char begA1Str[]  = "beginning a1: ";
char nn09A1Str[] = "a1 (noneg09): ";
char procA1Str[] = "processed a1: ";
char procA2Str[] = "          a2: ";
char procA3Str[] = "          a3: ";
char dacStr[]    = "Do another case? (n or N = no, others = yes) ";
char dlStr[]     = "================================";
char byeStr[]    = "bye...";

int main()
{
               char reply;
               int used1,
                   used2,
                   used3,
                   target,
                   intHolder,
                   count,
                   iter,
                   *hopPtr1,
                   *hopPtr11,
                   *hopPtr2,
                   *hopPtr3,
                   *endPtr1,
                   *endPtr2,
                   *endPtr3;

               reply = 'y';
               while (reply != 'n' && reply != 'N') //begW1
               //goto WTest1;
//begW1:
               {
                  used1 = 0;
                  hopPtr1 = a1;
                  while (reply != 'n' && reply != 'N')  //begW2
                  //goto WTest2;
//begW2:
                  {   // W2 brack
                     cout << einStr;
                     cout << (used1 + 1);
                     cout << ':' << ' ';
                     cin >> *hopPtr1;
                     ++used1;
                     ++hopPtr1;

                     if (used1 < 12)
                     //if( used1 >=12 ) goto else1:
//begI1:
                     {
                        cout << emiStr;
                        cin >> reply;

                     // go to endI1;
                     }
//else1:
                     else
                     {
                        cout << moStr << 12 << ieStr << endl;
                        reply = 'n';
                     }
//endI1://

//WTest2:         //(reply != 'n' && reply != 'N')
                  //if (reply != 'n' && reply != 'N') goto begW2;
                  //if (reply == 'n') goto xitW2;
                  //if (reply != 'N') goto begW2;
//endW2://
                  }    //endW2 brack
//xitW2:

                  cout << begA1Str;
                  if (used1 > 0)
                  //if( used1 <=0 ) goto endI2;
//begI2:
                  {
                     hopPtr1 = a1;
                     endPtr1 = a1 + used1;
                     do  //begDW1
//begDW1:
                     {
                        cout << *hopPtr1 << ' ' << ' ';
                        ++hopPtr1;
                     } //dw1 end brack
//endDW1://
//DWTest1://
                    while (hopPtr1 < endPtr1);
                    //if (hopPtr1 < endPtr1) goto begDW1;
//xitDW1: ??may not need

                  }
//endI2:
                  cout << endl;

                  if (used1 > 0)  //begI3
                  //if ( used <= 0) goto endI3;
//begI3:
                  {
                     for (hopPtr1 = a1, endPtr1 = a1 + used1;  //begF1
                                           hopPtr1 < endPtr1;
                                           ++hopPtr1)
                    //hopPtr1 = a1;
                    //endPtr1 = a1 + used1;
                    //goto FTest1;
//begF1:
                     {   // f1 beg bracket
                        target = *hopPtr1;

                        if (target < 0 || target > 9)
                        //if (target >=0) goto endI4;
                        //if (target <=9) goto endI4;       !!!!!!!!!!!!!!!!1!!!11 //check logic !!!!!!!!!!!
//begI4:
                        {
                           for (hopPtr11 = hopPtr1 + 1;  //begF2
                                    hopPtr11 < endPtr1;
                                             ++hopPtr11)
                    //hopPtr11 = hopPtr1 + 1;
                    //goto FTest2;
//begF2:
                           {  //f2 brack
                              *(hopPtr11 - 1) = *hopPtr11;
                            //  ++hopPtr11; //update
//FTest2:                   // if (hopPtr11 < endPtr1) goto begF2;
                           }
//endF2:
                           --used1;
                           --endPtr1;
                           --hopPtr1;
                        } //I4
//endI4://
                     //++hopPtr1; // update
//FTest1:            // if (hopPtr1 < endPtr1) goto begF1; // f1 test
                     } //endF1 brack
//endF1:
                     cout << nn09A1Str;
                     if (used1 > 0)
                     //if (used1 <= 0) goto endI5;
//begI5://
                     {
                        hopPtr1 = a1;
                        endPtr1 = a1 + used1;
                        do    //begDW2
//begDW2://
                        {
                           cout << *hopPtr1 << ' ' << ' ';
                           ++hopPtr1;
                        }
//endDW2://
//DWTest2://
                        while (hopPtr1 < endPtr1);
                        // if(hopPtr1 < endPtr1) goto begDW2;
//xitDW2:

                     } //I5
//endI5:
                     cout << endl;

                     used2 = 0;
                     used3 = 0;
                     hopPtr1 = a1;
                     hopPtr2 = a2;
                     hopPtr3 = a3;
                     endPtr1 = a1 + used1;
                     while (hopPtr1 < endPtr1)  //begW3
                     //goto WTest3;
//begW3:
                     { //w3 brack
                        intHolder = *hopPtr1;
                        *hopPtr2 = intHolder;
                        ++used2;
                        ++hopPtr2;
                        *hopPtr3 = intHolder;
                        ++used3;
                        ++hopPtr3;
                        ++hopPtr1;
//WTest3:            // if(hopPtr1 < endPtr1) goto begW3;
                     }   //endW3 brack
//endW3://

                     iter = 0;

                     do //
//begDW3://
                     {
                        ++iter;
                        count = 0;
                        if (iter == 1)  //begI6
                        //if(iter != 1) goto else6;
//begI6://
                        {
                           for (hopPtr1 = a1, endPtr1 = a1 + used1;  // begF3
                                                 hopPtr1 < endPtr1;
                                                          ++hopPtr1)
                           //hopPtr1 = a1;
                           //endPtr1 = a1 + used1;
                           //goto FTest3;
//begF3:
                           { //F3 brack
                              target = *hopPtr1;
                              if (target != 5)  //begI7
                              //if (target == 5)  goto else7;
//begI7:
                              {
                                 ++count;
                                 //goto endI7;
                              }
                              else
//else7://
                              {
                                 if (count != 0)  //I8:
                                 //if (count == 0) goto endI8;
//begI8://
                                 {
                                    *(hopPtr1 - count) = *hopPtr1;
                                 } //I8
//endI8://
                              }  //I7
//endI7://
                           // ++hopPtr1; //update F3
//FTest3:                  // if(hopPtr1 < endPtr1) goto begF3;
                           }  //endF3 brack
//endF3:
                           used1 -= count;
                           if (used1 == 0)
                           //if (used1 != 0) goto endI9;
//begI9:
                           {
                              hopPtr1 = a1;
                              *hopPtr1 = -99;
                              ++used1;
                           }    //I9
//endI9:
                        }
                        else   //else6
//else6://
                        {
                           if (iter == 2) //begI10
                           //if (iter != 2) goto else10;
//begI10:
                           {
                              for (hopPtr2 = a2, endPtr2 = a2 + used2;    //begF4
                                                    hopPtr2 < endPtr2;
                                                             ++hopPtr2)
                             //hopPtr2 = a2;
                             //endPtr2 = a2 + used2;
                             //goto FTest4;
//begF4:
                              { //F4 brack beg
                                 target = *hopPtr2;
                                 if (target > 4)   //I11
                                 //if (target <= 4) goto else11;
//begI11:
                                 {
                                    ++count;
                                    //goto endI11;
                                 }
                                 else //else11
//else11://
                                 {
                                    if (count != 0)   //I12
                                    //if (count == 0) goto endI12;
//begI12://
                                    {
                                       *(hopPtr2 - count) = *hopPtr2;
                                    }  //I12
//endI12:
                                 }  //I11 end brack
//endI11://
                              // ++hopPtr2; //update
//FTest4:                     // if(hopPtr2 < endPtr2) goto begF4;
                              }  //endF4 brack
//endF4 brack;
                              used2 -= count;

                              if (used2 == 0)  //I13
                              //if (used2 != 0) goto endI13;
//begI13:
                              {
                                 hopPtr2 = a2;
                                 *hopPtr2 = -99;
                                 ++used2;
                              }  //I13
//endI13:
                           }
                           else //else10
//else10://
                           {
                              for (hopPtr3 = a3, endPtr3 = a3 + used3;  //begF5
                                                    hopPtr3 < endPtr3;
                                                             ++hopPtr3)
                              //hopPtr3 = a3, endPtr3 = a3 + used3;
                              // goto FTest5;
//begF5:
                              { // beg f5 brack
                                 target = *hopPtr3;

                                 if (target < 6)    //I14
                                 // if (target >=6) goto else14;
//begI14:
                                 {
                                    ++count;
                                    //goto endI14;
                                 }  //
                                 else  //else 14
//else14:
                                 {  //
                                    if (count != 0)     //I15
                                    // if (count == 0) goto endI15;
//begI15://
                                    {
                                       *(hopPtr3 - count) = *hopPtr3;
                                    }  //endI15
//endI15://
                                 } //endI14
//endI14://
                              // ++hopPtr3; //update
//FTest5:                     //if (hopPtr3 < endPtr3) goto begF5;
                              } //endF5 brack
//endF5:
                              used3 -= count;
                              if (used3 == 0) //I16
                              //if (used3 != 0) goto endI16;
//begI16://
                              {
                                 hopPtr3 = a3;
                                 *hopPtr3 = -99;
                                 ++used3;
                              }  //endI16 brack
//endI16://
                           }  //endI10
//endI10://
                        }   //end I 6
//endI6://
                     } //endDW3 brack
//endDW3://
//DWTest3:  //
                     while (iter < 3);
                     //if (iter < 3) goto begDW3;
//xitDW3:
//cout << used3 << "  used3  ";                                     //!!!!!!!!!!!!!!!!!!!!!!!

                  }  //endI3
//endI3:

                  cout << procA1Str;
                  if (used1 > 0)       //begI17
                  //if (used1 <= 0) goto endI17;
//begI17:
                  {
                     hopPtr1 = a1;
                     endPtr1 = a1 + used1;
                     do    //begDW4
//begDW4://
                     {
                        cout << *hopPtr1 << ' ' << ' ';
                        ++hopPtr1;
                     }
//endDW4://
//DWTest4://
                     while (hopPtr1 < endPtr1);   //endDW4
                     //if(hopPtr1 < endPtr1) goto begDW4;
//xitDW4:
                  } //endI17
//endI17://
                  cout << endl;

                  cout << procA2Str;
                  if (used2 > 0)   //begI18
                  //if (used2 <= 0) goto endI18;
//begI18:
                  {
                     hopPtr2 = a2;
                     endPtr2 = a2 + used2;
                     do   //begDW5
//begDW5://
                     {
                        cout << *hopPtr2 << ' ' << ' ';
                        ++hopPtr2;
                     }
//endDW5://
//DWTest5://
                     while (hopPtr2 < endPtr2);
                     //if (hopPtr2 < endPtr2) goto begDW5;
//xitDW5:

                  }  //endI18
//endI18:
                  cout << endl;

                  cout << procA3Str;
                  if (used3 > 0) //begI19
                  //if (used3 <= 0) goto endI19;
//begI19:
                  {
                     hopPtr3 = a3;
                     endPtr3 = a3 + used3;
                     do  //begDW6
//begDW6://
                     {
                        cout << *hopPtr3 << ' ' << ' ';
                        ++hopPtr3;
                     }
//endDW6://
//DWTest6://
                     while (hopPtr3 < endPtr3);
                     //if (hopPtr3 < endPtr3) goto begDW6;
//xitDW6:
                  }  //endI19
//endI19:
                  cout << endl;

                  cout << dacStr;
                  cin >> reply;

//WTest1:      //(reply != 'n' && reply != 'N')
               //if (reply != 'n' && reply != 'N') goto begW1;
               //if (reply == 'n') goto xitW1;
               //if (reply != 'N') goto begW1;

//endW1://
               }  //end W1 brack
//xitW1:

               cout << dlStr << '\n';
               cout << byeStr << '\n';
               cout << dlStr << '\n';

               return 0;
}
