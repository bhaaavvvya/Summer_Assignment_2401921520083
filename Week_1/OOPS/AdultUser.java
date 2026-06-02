public class AdultUser implements LibraryUser
{

    int age;
    String bookType;

    void setAge(int age)
    {
        this.age = age;
    }

    void setBookType(String bookType)
    {
        this.bookType = bookType;
    }
    
    public void registerAccount()
    {
        if(age >= 12)
            System.out.println("You have successfully registered under an Adults account!");
        else
            System.out.println("Sorry! Age must be greater than or equal to 12 to register as an adult.");
    }

    public void requestBook()
    {
        if(bookType.equals("Fiction"))
            System.out.println("Book issued successfully! Please return the book within 7 days.");
        else
            System.out.println("Oops! You are allowed to take only adult fiction books.");
    }
}
