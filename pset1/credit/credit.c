#include <cs50.h>
#include <stdio.h>

int main(void) {
    
    long cc_number = get_long("Number: ");
    long temp = cc_number;
    int digit_count = 0;
    int other_sum = 0, non_other_sum = 0, total = 0;
    string company = "";
    
    while(temp > 0) 
    {
        int digit = temp % 10;
        temp = temp / 10;
        
        digit_count++;
    
        if (digit_count > 1 && digit_count % 2 == 0) 
        {
            int product = (digit * 2);
            
            if (product > 9) {
                
                product = (product / 10) + (product % 10); 
            }
            
            other_sum += product;
        }
        else 
        {
           
            non_other_sum += digit;
        }
    }
     
    total = other_sum + non_other_sum;
     
    if (total % 10 == 0)
    { 
        if (digit_count >= 13 && digit_count <= 16)
        {
            temp = cc_number;
            int up_to = digit_count - 2;
            
            for(int count = 0; count < up_to; count++) {
                temp = temp / 10;
            }
        
            if ( (temp == 34 || temp == 37) && (digit_count == 15)) 
            {
                company = "AMEX\n";  
            }
            else if ( (temp >= 51 && temp <= 55) && digit_count == 16)
            {
                company = "MASTERCARD\n";
            }
            else if ( (temp >= 40 && temp <= 49) && (digit_count == 16 || digit_count == 13))
            {
                company = "VISA\n";
            }
            else 
            {
                company = "INVALID\n";
            }
            
        }
        else
        {
            company = "INVALID\n";
        }
    }
    else
    {
        company = "INVALID\n";
    }

    printf("%s", company);
    
}