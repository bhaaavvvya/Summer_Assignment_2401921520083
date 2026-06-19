public class TestCompartment 
{
    public static void main(String[] args) 
    {
        Compartment[] arr = new Compartment[10];
        for(int i = 0; i < arr.length; i++)
        {
            int n = (int)(Math.random() * 4) + 1;
    
            switch(n)
            {
                case 1:
                    arr[i] = new FirstClass();
                    break;
                case 2:
                    arr[i] = new Ladies();
                    break;
                case 3:
                    arr[i] = new General();
                    break;
                case 4:
                    arr[i] = new Luggage();
                    break;
            }
        }
        System.out.println("Compartment Notices:");
        for(int i = 0; i < arr.length; i++)
        {
            System.out.println((i + 1) + ". " + arr[i].notice());
        }
    }
}
