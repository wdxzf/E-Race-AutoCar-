#include "Gray.h"
bool Gray_Val[12] ={0};

void Gray_get()
{
    Gray_Val[0] = Gray0 ? 1 : 0;
    Gray_Val[1] = Gray1 ? 1 : 0;
    Gray_Val[2] = Gray2 ? 1 : 0;
    Gray_Val[3] = Gray3 ? 1 : 0;
    Gray_Val[4] = Gray4 ? 1 : 0;
    Gray_Val[5] = Gray5 ? 1 : 0;
    Gray_Val[6] = Gray6 ? 1 : 0;
    Gray_Val[7] = Gray7 ? 1 : 0;
    Gray_Val[8] = Gray8 ? 1 : 0;
    Gray_Val[9] = Gray9 ? 1 : 0;
    Gray_Val[10] = Gray10 ? 1 : 0;
    Gray_Val[11] = Gray11 ? 1 : 0;
}

float Gray_erro()
{
    float Gray_ek_1 = 0,Gray_ek_2 = 0;
    float weights[12] = {38, 28, 20, 15, 9, 5, 5, 9, 15, 20, 28, 38};
    
    uint8_t i = 0;
    
   for(i = 11; i >= 6; i--)
  {
      if(Gray_Val[i])
      {
          Gray_ek_2 = Gray_Val[i] * weights[i];
          break;
      }
  }
    for(i = 0; i <= 5; i++)
  {
      if(Gray_Val[i])
      {
          Gray_ek_1 = Gray_Val[i] * weights[i];
          break;
      }
  }
return  func_limit((Gray_ek_1 - Gray_ek_2), 100);

}

//    if(Gray_Val[11]&&(Gray_Val[0]| 
//            Gray_Val[1]| 
//            Gray_Val[2]| 
//            Gray_Val[3]| 
//            Gray_Val[4]| 
//            Gray_Val[5]| 
//            Gray_Val[6]| 
//            Gray_Val[7]| 
//            Gray_Val[8]| 
//            Gray_Val[9]| 
//            Gray_Val[10])) Gray_ek_1 = -40;
//    
//           
//  
//    else if(Gray_Val[0]&&(Gray_Val[11]| 
//            Gray_Val[1]| 
//            Gray_Val[2]| 
//            Gray_Val[3]| 
//            Gray_Val[4]| 
//            Gray_Val[5]| 
//            Gray_Val[6]| 
//            Gray_Val[7]| 
//            Gray_Val[8]| 
//            Gray_Val[9]| 
//            Gray_Val[10])) Gray_ek_1 = 40;

//else
//    Gray_ek_1 
//    = 
//    (Gray_Val[0] * 20 + Gray_Val[1] * 16 + Gray_Val[2] * 13
//    + 
//    Gray_Val[3] *  9  + Gray_Val[4] *  7 + Gray_Val[5] * 5)

//    -

//    (Gray_Val[11] * 20 + Gray_Val[10] * 16 + Gray_Val[9] * 13
//    + 
//     Gray_Val[8]   * 9 + Gray_Val[7]  * 7 + Gray_Val[6] * 5);