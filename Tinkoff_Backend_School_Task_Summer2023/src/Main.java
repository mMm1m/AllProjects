import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args)
    {
    }
}

class Command
{

}

class CommandBody
{
   String device_name;
   Properties properties;
   CommandBody(String d)
   {
       this.device_name = d;
   }
   CommandBody(String d, Properties p)
   {
       this.device_name = d;
       this.properties = p;
   }
}

class Properties
{
    String name;
}

interface Device
{
    CommandBody WHOISARE(String destination);
    CommandBody IAMHERE();
}

class SmartHub implements Device
{
    String name;
    SmartHub(String name)
    {
        this.name = name;
    }
    @Override
    public CommandBody WHOISARE(String destination) {
        return IAMHERE();
    }

    @Override
    public CommandBody IAMHERE() {
        return new CommandBody(this.name);
    }
}

class EnvSensor implements Device
{
    String name;
    EnvSensor_Properties properties;

    class EnvSensor_Properties extends Properties
    {
        byte[] sensors;
        //byte[] triggers = new byte[5];
        EnvSensor_Properties(byte[] s)
        {
          sensors = s;
        }
    }

    @Override
    public CommandBody WHOISARE(String destination) {
        return IAMHERE();
    }

    @Override
    public CommandBody IAMHERE() {
        return new CommandBody(this.name,properties =  new EnvSensor_Properties(properties.sensors=new byte[4]));
    }

    public int[] STATUS(int temperature, int wetness, int illumination, int dirty)
    {
        return new int[] {temperature, wetness, illumination, dirty};
    }
}

class Switch implements Device
{
    String name;
    Switch_Properties switchProperties;
    class Switch_Properties extends Properties
    {
        ArrayList<String> devices;
        byte on_off;
        Switch_Properties(ArrayList<String> arrayList, byte b)
        {
            devices = arrayList;
            on_off = b;
        }
    }
    @Override
    public CommandBody WHOISARE(String destination) {
        return IAMHERE();
    }

    @Override
    public CommandBody IAMHERE() {
        return new CommandBody(this.name, new Switch_Properties(new ArrayList<String>(), switchProperties.on_off = 0));
    }
}

class Lamp implements Device
{

    @Override
    public CommandBody WHOISARE(String destination) {
        return null;
    }

    @Override
    public CommandBody IAMHERE() {
        return null;
    }
}

class Socket implements Device
{

    @Override
    public CommandBody WHOISARE(String destination) {
        return null;
    }

    @Override
    public CommandBody IAMHERE() {
        return null;
    }
}

class Timer
{

}
