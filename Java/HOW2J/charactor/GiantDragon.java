package charactor;

public class GiantDragon {
	private GiantDragon() {
		
	}
	
	private static GiantDragon instance = new GiantDragon();
	
	public static GiantDragon getInstance() {
		return instance;
	}
}
