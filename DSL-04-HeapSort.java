import java.util.Scanner;

public class HeapSort {
    public static void heapSort(int[] arr)
    {
        int n = arr.length;
        
        //build max heap
        for(int i = n/2 -1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
        
        // extracting one element
        for(int i = n-1; i > 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            
            heapify(arr, i , 0);
        }
    }
    
    public static void heapify(int[] arr, int n, int i)
    {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
            
        if(right < n && arr[right] > arr[largest])
            largest = right;
            
        if(largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
            
            heapify(arr, n, largest);
        }
    }
    
    public static void printArray(int[] arr)
    {
        for(int num : arr)
        {
            System.out.println(num + " ");
        }
        // System.out.println();
    }
    
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the number of elements : ");
        int n = scanner.nextInt();
        
        if(n <= 0)
        {
            System.out.println("Invalid size. Must be greater than 0.");
            return;
        }
        
        int[] arr = new int[n];
        System.out.println("Enter the  elements of the array : ");
        for(int i = 0; i < n; i++)
        {
            arr[i] = scanner.nextInt();
        }
        
        System.out.println("Original Array : ");
        printArray(arr);
        
        heapSort(arr);
        
        System.out.println("Sorted Array : ");
        printArray(arr);
        
        scanner.close();
    }
}