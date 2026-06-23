public class Box3d extends Box
{
    private int h;

    Box3d()
    {
        super();
        h = 0;
    }

    Box3d(int x, int y, int z)
    {
        super(x, y);
        h = z;
    }

    void printVolume()
    {
        System.out.println("Volume: " + (l * b * h));
    }
}