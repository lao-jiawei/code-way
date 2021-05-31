package 额外例题;
abstract class Animal{
	protected String name;
	public Animal(String objName) {
		name=objName;
	} 
	protected abstract void show();
} 

class Elephant extends Animal{
	private int age =0;
	public Elephant(String objName,int objAge) {
		super(objName);
		age=objAge;
	}
	public void show() {
		String massage="我是一只温暖的大象";
		massage+="\n我的名字叫"+name;
		massage+="\n我的年龄是"+age+"岁";
		System.out.println(massage);
	}
}

class Monkey extends Animal{
	private String coatColor;
	public Monkey(String objName,String color) {
		super(objName);
		coatColor=color;
	}
	public void show() {
		String massage="我是一只可爱的小猴";
		massage+="\n我的名字叫"+name;
		massage+="\n我有着一身"+coatColor+"的毛发";
		System.out.println(massage);
	}
}

public class AnimalDemo {
	public static void main(String[] args) {
		Elephant elephant = new Elephant("吉隆球",16);
		elephant.show();
		Monkey monkey=new Monkey("跳跳鬼","金黄色");
		monkey.show();
		}
}
