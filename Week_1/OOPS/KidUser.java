class KidUser implements LibraryUser
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
        if(age < 12)
            System.out.println("You have successfully registered under a Kids account!");
        else
            System.out.println("Sorry! Age must be less than 12 to register as a kid.");
    }

    public void requestBook()
    {
        if(bookType.equals("Kids"))
            System.out.println("Book issued successfully! Please return the book within 10 days.");
        else
            System.out.println("Oops! You are allowed to take only kids book.");
    }
}
