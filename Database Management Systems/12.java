import com.mongodb.*;
import java.util.*;

public class connection
{
 	public static void main( String args[] )
 	{
          	try
          	{
         	
             	MongoClient mongoClient = new MongoClient( "localhost" , 27017 );
             	
             	DB db = mongoClient.getDB( "assn12" );
             	System.out.println("Connect to database successfully");
           	 
             	while(true)
             	{
                 	System.out.println("\n1. Create Collection\n 2. Insert Document\n 3. Update Document\n 4. Remove Document\n 5. Exit\n");
                 	Scanner in =new Scanner(System.in);
                 	String ch;
                 	ch=in.nextLine();
                 	switch(ch)
                 	{
                		 case "1":  
                			 DBCollection coll = db.createCollection("stud", null);
                        	System.out.println("Collection created successfully");
                        	DBCollection coll1 = db.getCollection("stud");
                        	System.out.println("Collection stud selected successfully");
                        	break;
                		 case "2":  
                			 coll=db.getCollection("stud");
                        	BasicDBObject doc = new BasicDBObject("Title", "MongoDB").
                        	append("roll_no", 233).
                        	append("grade", "A+").
                        	append("url", "http://www.docs.mongodb.org/").
                        	append("Marks", "100");
                        	coll.insert(doc);
                        	System.out.println("Document inserted successfully");
                        	System.out.println("Documents in collection are as follows");
                        	DBCursor cursor =  coll.find();
                        	int i=1;
                        	while (cursor.hasNext())
                        	{
                       		 System.out.println("Inserted Document: "+i);
                            	System.out.println(cursor.next());
                            	i++;
                        	}
                        	break;
                		 case "3":  
                			 coll=db.getCollection("stud");                                                   	 
                        	doc = new BasicDBObject("Title", "MongoDB").
                        	append("roll_no", 233).
                        	append("grade", "A+").
                        	append("url", "http://www.docs.mongodb.org/").
                        	append("Marks", "100");
               	 
                        	BasicDBObject doc1=new BasicDBObject("name", "xyz").
                        	append("roll_no", 340).
                        	append("grade", "A");
                        	coll.update(doc,doc1);
                        	cursor =  coll.find();
                        	i=1;
                        	while (cursor.hasNext())
                        	{
                       		 System.out.println("Inserted Document: "+i);
                       		 System.out.println(cursor.next());
                       		 i++;
                        	}
                        	break;
                		 case "4":
                			 coll=db.getCollection("stud");
                			 DBObject mydoc=coll.findOne();
                			 coll.remove(mydoc);
                			 cursor=coll.find();
                			 int i1=1;
                			 while (cursor.hasNext())
                			 {
                				 System.out.println("Inserted Document: "+i1);
                				 System.out.println(cursor.next());
                				 i1++;
                			 }
                			 System.out.println("Document deleted successfully");
                			 break;
                		 case "5":  
                			 System.out.println("Exit....");
                			 System.exit(0);
                        	 
                  	}
               	 
              	}
           	 
          	}
             	 
          	 
          	catch(Exception e)
          	{
             	System.err.println( e.getClass().getName() + ": " + e.getMessage() );
          	}
  	}
}

