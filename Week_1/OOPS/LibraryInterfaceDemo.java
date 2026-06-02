class LibraryInterfaceDemo 
{
    public static void main(String[] args) 
    {
        System.out.println("KID USER ACCOUNT:");
        KidUser kid1 = new KidUser();
        System.out.println("Setting age of kid to 18:");
        kid1.setAge(18);
        kid1.registerAccount();
        System.out.println("Setting age of kid to 10:");
        kid1.setAge(10);
        kid1.registerAccount();
        System.out.println("Requesting FICTION book:");
        kid1.setBookType("Fiction");
        kid1.requestBook();
        System.out.println("Requesting KIDS book:");
        kid1.setBookType("Kids");
        kid1.requestBook();

        System.out.println("ADULT USER ACCOUNT:");
        AdultUser adult1 = new AdultUser();
        System.out.println("Setting age of adult to 5:");
        adult1.setAge(5);
        adult1.registerAccount();
        System.out.println("Setting age of adult to 23:");
        adult1.setAge(23);
        adult1.registerAccount();
        System.out.println("Requesting KIDS book:");
        adult1.setBookType("Kids");
        adult1.requestBook();
        System.out.println("Requesting FICTION book:");
        adult1.setBookType("Fiction");
        adult1.requestBook();
    }
}
