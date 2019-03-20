#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

/*********************************************************************
** Program Filename: Heat Diffusion program
** Author: za world
** Date: March 19 2019
** Description: Asks user if they want to calculate the heat Diffusion
** across either a plate or a wire given the properties of the material
** Input: command line argument for material properties and specifications
** for simulation
** Output: The tempertures of the plate/wire at each time interval
*********************************************************************/

using namespace std;
//a.out -u wire/plate -r (float) -k (conductivity) -c (capacity)

/*********************************************************************
** Function: u_checker
** Description: checks if user entered wire or plate
** Parameters: number of command line arguments and pointer to
** command line arguments
** Pre-Conditions: user entered 9 command line arguments
** Post-Conditions: user entered either wire or plate
*********************************************************************/
int u_checker(int argc, char **argv){
  int count =0;
  char w[] = "wire";
  char s[] = "-u";
  char p[] ="plate";
  for(int i=0; i<argc; i++){

    if(strcmp(argv[i],s) == 0){
  count++;
      if(strcmp(argv[i+1], w) == 0){
        //1 means wire
        return 1;
      }
      else if(strcmp(argv[i+1], p)==0){
        //2 means plate
        return 2;
      }
    }
  }
  if(count==0){
    cout << "not foumnd" << endl;
    exit(0);
  }
}
/*********************************************************************
** Function: r_checker
** Description: stores the -r value
** Parameters: number of command line arguments and pointer to
** command line arguments
** Pre-Conditions: user entered 9 command line arguments
** Post-Conditions: -r value is a float
*********************************************************************/
float r_checker(int argc, char **argv){
  int count = 0;
  for(int i=0; i<argc; i++){
    char s[]="-r";
    if(strcmp(argv[i],s) == 0){
      int length = strlen(argv[i+1]);
        for(int j =0; j<length;j++){
          if(argv[i+1][j]!='.' && !(argv[i+1][j] >= '0' && argv[i+1][j] <='9')){
            exit(0);
          }
          else{
            return atof(argv[i+1]);
          }
        }
      }
    }
  }
  /*********************************************************************
  ** Function: r_checker
  ** Description: stores the -r value
  ** Parameters: number of command line arguments and pointer to
  ** command line arguments
  ** Pre-Conditions: user entered 9 command line arguments
  ** Post-Conditions: -k value is a float
  *********************************************************************/
  float k_checker(int argc, char **argv){
      int count = 0;
      for(int i=0; i<argc; i++){
        char s[]="-k";
        if(strcmp(argv[i],s) == 0){
          int length = strlen(argv[i+1]);
            for(int j =0; j<length;j++){
              if(argv[i+1][j]!='.' && !(argv[i+1][j] >= '0' && argv[i+1][j] <='9')){
                exit(0);
              }
              else{

                return atof(argv[i+1]);
              }
            }
          }
        }
      }

      /*********************************************************************
      ** Function: c_checker
      ** Description: stores the -c value
      ** Parameters: number of command line arguments and pointer to
      ** command line arguments
      ** Pre-Conditions: user entered 9 command line arguments
      ** Post-Conditions: -c value is a float
      *********************************************************************/
            float c_checker(int argc, char **argv){
              int count = 0;
              for(int i=0; i<argc; i++){
                char s[]="-c";
                if(strcmp(argv[i],s) == 0){
                  int length = strlen(argv[i+1]);
                    for(int j =0; j<length;j++){
                      if(argv[i+1][j]!='.' && !(argv[i+1][j] >= '0' && argv[i+1][j] <='9')){
                        exit(0);
                      }
                      else{
                        return atof(argv[i+1]);
                      }
                    }
                  }
                }
              }

/*********************************************************************
** Function: stable_checker
** Description: checks  if input is stable
** Parameters: simulation specifications, k, c, r values
** Pre-Conditions: simulation specificatinos, k, c,r have been initialized
** Post-Conditions: simulation is stable
*********************************************************************/
int stable_checker(float *user_data, float k, float c, float r){
  float delta_x = user_data[0] / user_data[1];
  float delta_time = user_data[3]/user_data[2];
  float stable = (k * delta_time)/(pow(delta_x,2) * c *r);
  if(stable >= -0.5 || stable <=0.5){
    return 1;
  }
  else{
    return 0;
  }

}
/*********************************************************************
** Function: error_handle
** Description: checks input is a number
** Parameters: ascii values of numbers
** Pre-Conditions: output prompt
** Post-Conditions: input is a number
*********************************************************************/
float error_handle(int min, int max){
    int good_input = 0;
    string user_input;
    while (good_input == 0){
        int counter = 0;
        getline(cin, user_input);
        if(user_input.size() == 0){
            cout << "Enter valid input" << endl;
        }
        else{
        //checks if each character inputed is between 0-9
        for (int i = 0; i < user_input.size(); i++){
            if (int(user_input.at(i)) <min|| int(user_input.at(i)) > max){
                counter++;
            }
            if(user_input.at(i)=='.'){
              counter--;
            }
        }
            //checks edge case of first number being 0
        if (counter > 0){
            cout << "Enter valid input" << endl;
        }
        else
        {
            good_input = 1;
        }
        }
    }
    return atof(user_input.c_str());
}
/*********************************************************************
** Function:  user_alloc
** Description: stores simulation specificiations
** Parameters: pointer to simulation specificiations
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void user_alloc(float *user_data){
    cout << "Enter wire length" << endl;
    float temp = 0;
    temp=error_handle(48,57);
    user_data[0] = temp;
    cout << "Enter # of sections" << endl;
    temp=error_handle(48,57);
    user_data[1] = temp;
    cout << "Enter time intervals" << endl;
    temp=error_handle(48,57);
    user_data[2] = temp;
    cout << "Enter time of simulation" << endl;
    temp=error_handle(48,57);
    user_data[3] = temp;
    cout << "Enter right temp" << endl;
    temp=error_handle(48,57);
    user_data[4] = temp;
    cout << "Enter left temp" << endl;
    temp=error_handle(48,57);
    user_data[5] = temp;
    cout << "Enter initial temp" << endl;
    temp=error_handle(48,57);
    user_data[6] = temp;
}
/*********************************************************************
** Function: user_plate_alloc
** Description: stores simulation specificiations
** Parameters: pointer to simulation specificiations
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void user_plate_alloc(float *user_data){
    cout << "Enter plate length" << endl;
    float temp = 0;
    temp=error_handle(48,57);
    user_data[0] = temp;
    cout << "Enter # of sections" << endl;
    temp=error_handle(48,57);
    user_data[1] = temp;
    cout << "Enter time intervals" << endl;
    temp=error_handle(48,57);
    user_data[2] = temp;
    cout << "Enter time of simulation" << endl;
    temp=error_handle(48,57);
    user_data[3] = temp;
    cout << "Enter top/bottom temp" << endl;
    temp=error_handle(48,57);
    user_data[4] = temp;
    cout << "Enter left/right temp" << endl;
    temp=error_handle(48,57);
    user_data[5] = temp;
    cout << "Enter initial temp" << endl;
    temp=error_handle(48,57);
    user_data[6] = temp;
}
/*********************************************************************
** Function: wire_allocate
** Description: creates wire with dimensions specified in user_data
** Parameters: pointer to simulation specificiations
** Pre-Conditions: n/a
** Post-Conditions:n/a
*********************************************************************/
float **wire_allocate(float *user_data){
  int delta_x = int(user_data[1]);
  //int delta_time = user_data[2];
  float **heat_diffusion = new float *[int(user_data[2])];
  for(int i =0; i<int(user_data[2]);i++){
    heat_diffusion[i]= new float[delta_x];
  }
  return heat_diffusion;
}
/*********************************************************************
** Function: temp_allocate
** Description:  stores values into array from simulation specifications
** Parameters: pointer to simulation specificiations, pointer to wire
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void temp_allocate(float *user_data, float **heat_diffusion){
  for(int i =0; i<int(user_data[2]); i++){
    heat_diffusion[i][0] = user_data[5];
    heat_diffusion[i][int(user_data[1])-1] = user_data[4];
  }
  for(int j = 0; j<int(user_data[2]); j++){
    for(int k =1; k<int(user_data[1])-1;k++){
      heat_diffusion[j][k] = 0;
    }
  }
}
/*********************************************************************
** Function: temp_calculate
** Description: calculates the tempture of wire for each time
** Parameters: pointer to simulation specificiations, pointer to wire,
**k,c,r
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void temp_calculate(float *user_data, float **heat_diffusion, float k, float c, float r){
  float delta_x = user_data[0] / user_data[1];
  float delta_time = user_data[3] / user_data[2];
  for(int i=1; i<int(user_data[2])-1; i++){
    for(int j=1; j<int(user_data[1])-1; j++){
        /*float u_last=heat_diffusion[i-1][j-1];
        float u=heat_diffusion[i-1][j];
        float u_next=heat_diffusion[i-1][j+1];
        cout <<"this left" << u_last << endl;
        cout<< "this right" << u_next << endl;
        cout<< "this middle" << u << endl;
        float part_1 = delta_time*k;
        float part_2 = u_last+u_next-(2*u);
        float part_3 =c*r*delta_x*delta_x;
      heat_diffusion[i][j] = (((part_1*part_2)/part_3)+u);*/
      float part_1 = delta_time*k;
      float part_2 = heat_diffusion[i-1][j+1]-(2*heat_diffusion[i-1][j])+heat_diffusion[i-1][j-1];
      float part_3 = c*r*delta_x*delta_x;
      heat_diffusion[i][j] = (((part_1*part_2)/part_3) + heat_diffusion[i-1][j]);

    }

  }
}
/*********************************************************************
** Function: print_wire
** Description: prints tempurture of wire
** Parameters: pointer to simulation specificiations, pointe to wire
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void print_wire(float *user_data, float **heat_diffusion){
  for(int i =0; i<int(user_data[2]);i++){
    for(int j=0; j<int(user_data[1]);j++){
      cout << setw(4) << " " << heat_diffusion[i][j];
    } cout << endl;
  }
}
/*********************************************************************
** Function: print_plate
** Description: prints tempurture of plate
** Parameters: pointer to simulation specificiations, pointer to wire
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void print_plate(float *user_data, float **heat_diffusion){
  for(int i =0; i<int(user_data[1]);i++){
    for(int j=0; j<int(user_data[1]);j++){
      cout << setw(4) << " " << heat_diffusion[i][j];
    } cout << endl;
  }
}
/*********************************************************************
** Function: deallocate_wire
** Description: deletes pointers
** Parameters: pointer to simulation specificiations, pointer to wire
** Pre-Conditions: pointers have been created
** Post-Conditions: no memory leaks
*********************************************************************/
void deallocate_wire(float *user_data, float **heat_diffusion){
  for(int i =0; i<int(user_data[2]);i++){
    delete [] heat_diffusion[i];
  }
  delete [] heat_diffusion;
  delete [] user_data;
}

/*********************************************************************
** Function: plate_calculate
** Description: uses old plate to calculate the next temperture of time
** interval then resets new plate as old and continues for all time intervals
** Parameters: pointer to simulation specificiations, pointer to old plate
**pointer to new plate, k,c,r
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
void plate_calculate(float *user_data, float **pre, float ** post, float k, float c, float r){
  float delta_x = user_data[0] / user_data[1];
  float delta_time = user_data[3] / user_data[2];
  for(int i=1; i<int(user_data[2])-1;i++){
    for(int j=1; j<int(user_data[1])-1;j++){
        pre[i][j]=post[i][j];
    }
  }
  for(int i=1; i<int(user_data[2])-1;i++){
    for(int j=1; j<int(user_data[1])-1;j++){
      float part1= (delta_time * k)/(c*r);
      float part2 = (pre[i+1][j] -2*pre[i][j]+pre[i-1][j])/(delta_x*delta_x);
      float part3 = (pre[i][j+1]-2*pre[i][j] + pre[i][j-1])/(delta_x*delta_x);
     post[i][j]= (part1 * (part2 + part3))+pre[i][j];
    }
  }
  print_plate(user_data, post);
}

/*********************************************************************
** Function: plate_allocate
** Description: stores tempertures based on plate specifications
** Parameters: pointer to simulation specificiations and pointer to plate
** Pre-Conditions: pointer to user data has been created
** Post-Conditions:n/a
*********************************************************************/
float **plate_allocate(float *user_data, float **plate){
  for(int i=0; i<int(user_data[1]);i++){
    for(int j=0; j<int(user_data[1]);j++){
      plate[i][j]=0;
    }
  }
  for(int i=0; i<int(user_data[1]);i++){
    plate[0][i] = user_data[4];
    plate[int(user_data[1])-1][i] = user_data[4];
  }
  for(int i=1; i<int(user_data[1])-1;i++){
    plate[i][0]=user_data[5];
    plate[i][int(user_data[1])-1]=user_data[5];
  }


  /*********************************************************************
  ** Function: deallocate_plate
  ** Description: deallocates all pointers for plates
  ** Parameters: pointer to simulation specificiations, pointer to old plate
  ** pointer to new plate
  ** Pre-Conditions: pointer to user data has been created
  ** Post-Conditions: no memory leaks
  *********************************************************************/
}
void deallocate_plate(float *user_data, float **pre, float **post){
  for(int i =0; i<int(user_data[2]);i++){
    delete [] pre[i];
    delete [] post[i];

  }
  delete [] pre;
  delete [] post;
  delete [] user_data;
}
int main(int argc, char **argv){
  if(argc==9){
    int u = u_checker(argc, argv);
    float r = r_checker(argc, argv);
    float c = c_checker(argc, argv);
    float k = k_checker(argc, argv);
    if(u!=0 && r!=0 && c!=0 && k!=0){
      float *user_data = new float[7];
      //wire case
      if(u==1){
        user_alloc(user_data);
        int stable = stable_checker(user_data, k,c,r);
        if(stable==1){
        float **heat_diffusion = wire_allocate(user_data);
        temp_allocate(user_data, heat_diffusion);
        temp_calculate(user_data, heat_diffusion, k, c, r);
        print_wire(user_data, heat_diffusion);
        deallocate_wire(user_data, heat_diffusion);
      }
      else{
        cout << "Unstable, DX";
        exit(0);
      }
      }
      //plate case
      else if(u==2){
        user_plate_alloc(user_data);
        int stable = stable_checker(user_data, k,c,r);
        if(stable==1){
        float **pre_plate_diffusion = wire_allocate(user_data);
        float **post_plate_diffusion = wire_allocate(user_data);
        plate_allocate(user_data, pre_plate_diffusion);
        plate_allocate(user_data, post_plate_diffusion);
        for(int i =0; i<user_data[2];i++){
        plate_calculate(user_data, pre_plate_diffusion, post_plate_diffusion, k, c, r);
      }
        deallocate_plate(user_data, pre_plate_diffusion, post_plate_diffusion);
      }
      else{
        cout << "Unstable, DX";
        exit(0);
      }
      }
    }
    else{
      cout << "you died again";
      exit(0);
    }
  }
  else{
    cout << "you died";
    exit(0);
  }
return 0;
}
