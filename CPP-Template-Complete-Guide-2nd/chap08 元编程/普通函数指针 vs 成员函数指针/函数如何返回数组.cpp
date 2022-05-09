#include <iostream>


using namespace std;

float* add_bad(float a[3], float b[3])
{
    float sum[4];
    sum[0] = a[0] + b[0];
    sum[1] = a[1] + b[1];
    sum[2] = a[2] + b[2];
    return sum;
}

float* add_use_new(float a[3], float b[3])
{
    float* sum_new = new float[3];
    sum_new[0] = a[0] + b[0];
    sum_new[1] = a[1] + b[1];
    sum_new[2] = a[2] + b[2];
    return sum_new;
}

void add_sum_in_par(float a[3], float b[3], float sum[3])
{
    sum[0] = a[0] + b[0];
    sum[1] = a[1] + b[1];
    sum[2] = a[2] + b[2];
}

int main()
{
    
    float A[3] = { 1.0, 1.0, 1.0};
    float B[3] = { 1.0, 2.0, 3.0};
    
    cout << "\n---- don't return a local sum \n";
    // float*  = add_bad(A, B);
    // cout << C_bad[0] << " " << C_bad[1] << "  " << C_bad[2] << endl;
    // cout << C_bad[0] << " " << C_bad[1] << "  " << C_bad[2] << endl;

    cout << "\n---- using new in function definition \n";

    float* C_use_new = add_use_new(A, B);
    cout << C_use_new[0] << " " << C_use_new[1] << " " << C_use_new[2] << endl;
    cout << C_use_new[0] << " " << C_use_new[1] << " " << C_use_new[2] << endl;
    //! C_use_new  和  sum_new 指向同一个内存. ptr1 = ptr2 : ptr1 和 ptr2 指向同一个内存
    delete[] C_use_new; 

    cout << "\n---- put sum result in function args \n";
    float C_sum_in_par[3];
    add_sum_in_par(A, B, C_sum_in_par);
    cout << C_sum_in_par[0] << " " << C_sum_in_par[1] << " " << C_sum_in_par[2] << endl;
    cout << C_sum_in_par[0] << " " << C_sum_in_par[1] << " " << C_sum_in_par[2] << endl;

    return 0;
}

