

import ecomm.Portal;
import ecomm.Globals;

import java.io.*;
import java.util.Scanner;

public class DemoPortal extends Portal{
	private final String PortalId;
	private int RequestId;
	

	public DemoPortal(String PortalId){
		this.PortalId = PortalId;
		this.RequestId = 1;
	}
	
	public void processUserCommand(String command){
		String[] input = command.split("\\s+");
		if(input[0].equals("Check")){
			checkResponse();
		}else if(input[0].equals("Buy")){
			buyItem(input[1], input[2]);
		}else if(input[0].equals("List")){
			AskForItems(input[1]);
		}
	}

	public void checkResponse(){
		
	}

	public void buyItem(String productId, String numItems){
		try{
			FileWriter out = new FileWriter(Globals.toPlatform, true);
			out.write("" + PortalId + " " + RequestId + " Buy " + productId + " " + numItems + "\n");
			out.close();
		}catch(IOException e){
			System.out.println("IOException");
		}
	}

	public void AskForItems(String category){
		try{
			FileWriter out = new FileWriter(Globals.toPlatform, true);
			out.write("" + PortalId + " " + RequestId + " List " + category + "\n");
			out.close();
		}catch(IOException e){
			System.out.println("IOException");
		}
	}
}
