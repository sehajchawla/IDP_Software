//move complex

// void dodgeRed(){
//   if (north == true){
//     leftbackward90(); runtimeForward(10); leftforward90();
//     runtimeForward(15);
//     leftforward90(); rightforward90();
//   }
//   else if (north == false){
//     rightbackward90(); runtimeForward(10); rightforward90();
//     runtimeForward(15); //note 10 is crucial here
//     rightforward90(); leftforward90();
//   }
// }

//this function will set the diff_speed, which is crucial for feedForward function
//refresh rate 0.1s due to updateDiffDist()
//void feedbackDiffSpeed(){
//  if (side_distance1 < 40){feedbackSetup(10);}
//  else if (side_distance1 < 80){feedbackSetup(10);}
//  else if (side_distance1 < 120){feedbackSetup(10);}
//  else {feedbackSetup(10);}
//}
