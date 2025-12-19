beg = 0;  
end = size - 1;  
while ( beg <= end)  
  {  
    mid = (beg + end) / 2;  
     If (aarr[mid] == num)  
        {  
          return mid + 1;  
        }  
    else if (arr[mid] > num)  
    {  
    End = mid - 1;  
    }  
    Else if (arr [mid] < num)  
    {  
    Beg = mid + 1;  
    }  
}    
Return -1; 
