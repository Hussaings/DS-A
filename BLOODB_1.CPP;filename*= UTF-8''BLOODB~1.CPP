#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>

class person
{
   protected:
		char name[30], add[100];
		int age;
		double ph_no;

   public:
	     void getdata();
	     void putdata();
};

class donor: public person
{
   protected:
	      int d_id;
	      char bg_gr[5];
	      int qty;

   public:
	donor()
	{
		d_id=0;
	}
	~donor()
	{
	 //   finout.close();
	}
	  void d_delete();
	  friend void d_add(donor &);
	  void d_modify();
	  void d_search();
	  void d_display();
	  friend void D_main(donor &);
	  void d_group_search();
};

 class receiver: public person
   {
     protected:
		int r_id;
		char bg_gr[5];
		char cause[20];
		int qty;
     public:
		receiver()
		{
		  r_id=100;
		}
		~receiver()
		{
	     //	  finout.close();
		}
		void r_delete();
		friend void r_add(receiver &);
		void r_modify();
		void r_search();
		void r_display();
		friend void R_main(receiver &);


 };

 class employee:public person
 {
   protected:
		int emp_id ;
		long    salary;
		char dept[20];
   public:
		employee()
		{
		  emp_id=1000;
		}
		~employee()
		{
	       //			finout.close();
		}
		friend void e_add(employee &);
		void e_delete();
		void e_modify();
		void e_search();
		void e_display();
		friend void E_main(employee &);

  };

  class enquiry:public donor, public receiver, public employee
  {
    public:
	       int ch;
    public:
	  void enq();
  };

  //-----------function to accept data and display data ---------
     void person:: getdata()
	   {
		   cout<<"Enter name:"<<endl;
		   gets(name);
		   Age:
		   cout<<"Enter age"<<endl;
		   cin>>age;
		    if(age<=18 || age>=60)
		{
			cout<<"Not allowed to donate"<<endl;
		       goto Age;

		}
		   cout<<"Enter address"<<endl;
		   gets(add);
		   pno:
		   cout<<"Enter phone number"<<endl;
		   cin>>ph_no;
		   if(ph_no <= 1000000000.00F)
		{
			cout<<"invalid phone number"<<endl;
		       goto pno;
		}
	   }

	  void person:: putdata()
	  {         cout<<"\nName:"<<name<<endl;
		    cout<<"Age:"<<age<<endl;
		    cout<<"Add:"<<add<<endl;
		    cout<<"Phone no:"<<ph_no<<endl;
	  }

//-------------- Donor Module----------------
	void d_add(donor &d)
		{
		   fstream finout;
		   int n;
		   cout<<"Add donor"<<endl;
		   finout.open("donor.txt",ios::app);
		   if(finout.eof()!=0)
		   {
		      cout<<"Unable to open a file"<<endl;
		     exit(1);
		   }
		  else
		   {
		     d.getdata();
		     cout<<"donor id"<<++d.d_id<<endl;

		     blgr:
		     cout<<"Enter Blood group of donor:"<<endl;
		    gets(d.bg_gr);

		    if((strcmpi(d.bg_gr,"A+")!=0)&&(strcmpi(d.bg_gr,"A-")!=0) && (strcmpi(d.bg_gr,"B+")!=0) && (strcmpi(d.bg_gr,"B-")!=0) && (strcmpi(d.bg_gr,"AB+")!=0) && (strcmpi(d.bg_gr,"AB-")!=0) && (strcmpi(d.bg_gr,"O+")!=0) && (strcmpi(d.bg_gr,"O-")!=0))
		  {
		    cout<<"invalid blood group"<<endl;
		    goto blgr;
		  }

		    abc:
		    cout<<"Enter quantity of blood donoated(ml)"<<endl;
		    cin>>d.qty;
		if(d.qty>500)
		{
			cout<<"Access donation not allowed"<<endl;
			goto abc;
		}
		    finout.clear();
		    finout.seekp(ios::end);
		    finout.write((char*)&d, sizeof(d));
		    finout.close();

		  }
	    }



     void donor::d_delete()
	  {

	    donor d1;
	    int no;
	    cout<<"Enter donor id number to be deleted"<<endl;
	    cin>>no;

	    fstream finout1,finout2;
	    finout1.open("donor.txt",ios::in);
	    finout2.open("donor1.txt",ios::out);

	    if(finout1.eof()!=0)
	    {
		cout<<"Unable to open a first file";
		exit(1);
	    }
		if(finout2.eof()!=0)
		{
		  cout<<"Unable to open second file ";
		  exit(1);
		}
		   while(finout1.read((char*)&d1,sizeof(d1)))
		   {
		      if(d1.d_id==no)
			{
			}
		      else
			{
			  finout2.write((char*)&d1,sizeof(d1));
			}
		  }
		finout1.close();
		finout2.close();
		 remove("donor.txt");

		rename("donor1.txt","donor.txt");

	}


       void donor::d_modify()
		{
			donor d1;
			fstream finout;
			int n,r=0;
			cout<<"Modify Donor"<<endl;
			finout.open("donor.txt",ios::in|ios::out);
			if(finout.eof()!=0)
		       {
			    cout<<"Unable to open a file"<<endl;
			    exit(1);
		       }
		     else
		     {
			cout<<"Enter donor id to be modified"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&d1, sizeof(d1)))
			{
				if( n == d1.d_id)
				{

			cout<<"Enter new values\n";

		   d1.getdata();
		   d1.d_id = n;

		    blgr:
		    cout<<"Enter Blood group of donor:"<<endl;
		    gets(d1.bg_gr);

		    if((strcmpi(d1.bg_gr,"A+")!=0)&&(strcmpi(d1.bg_gr,"A-")!=0) && (strcmpi(d1.bg_gr,"B+")!=0) && (strcmpi(d1.bg_gr,"B-")!=0) && (strcmpi(d1.bg_gr,"AB+")!=0) && (strcmpi(d1.bg_gr,"AB-")!=0) && (strcmpi(d1.bg_gr,"O+")!=0) && (strcmpi(d1.bg_gr,"O-")!=0))
		  {
		    cout<<"invalid blood group"<<endl;
		    goto blgr;
		  }

		    abc:
		    cout<<"Enter quantity of blood donoated(ml)"<<endl;
		    cin>>d1.qty;
		   if(d1.qty>500)
		    {
			cout<<"Access donation not allowed"<<endl;
			goto abc;
		}
			long location=(r)*sizeof(d1);
			finout.seekp(location);
			finout.write((char*)&d1,sizeof(d1));


				n = -1;
				break;
				 }
				r++;
			}
			if(n != -1)
				cout<<"Not Found"<<endl;
			r++;
		}

			finout.clear();
			finout.close();
		     }


		void donor:: d_search()
		{
			donor d;
			fstream finout;
			int n;
			finout.open("donor.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			cout<<"Enter donor id to be search"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&d, sizeof(d)))
			{
				if( n == d.d_id)
				{
				d.putdata();
				n = -1;
				break;
				 }
			}
			if(n != -1)
				cout<<"Not Found"<<endl;

			finout.close();
		     }

	     }

	    void donor::d_group_search()
	    {
	    donor d;
			fstream finout;
			int n;
			char  gr[5];
			finout.open("donor.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			cout<<"Enter donor Group to be search"<<endl;
			cin>>gr;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&d, sizeof(d)))
			{
				if(strcmp(gr,d.bg_gr)==0)
				{
				d.putdata();
			    //	n =0;
			      //	break;
				 }
			}
			//if(n != -1)
			 //	cout<<"Not Found"<<endl;

			finout.close();
		     }

	    }

	void donor::d_display()
		{       donor d1;
			fstream finout;
			int n;
			finout.open("donor.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			while(finout.read((char*)&d1, sizeof(d1)))
			{
				d1.putdata();
				cout<<"donor id:"<<d1.d_id<<endl;
				cout<<"blood group:"<<d1.bg_gr<<endl;
			}

			finout.close();
		     }
		}
  //-------------------- main function for Donor-------------------

void D_main(donor &d)
		{
			int i;
			do
			{
				cout<<"1.Add donar"<<endl;
				cout<<"2.Delete donar"<<endl;
				cout<<"3.search donar"<<endl;
				cout<<"4.modify donar"<<endl;
				cout<<"5.display donar"<<endl;
				cout<<"6.exit"<<endl;
				cout<<"Enter option"<<endl;
				cin>>i;

				switch(i)
				{
					case 1:
						d_add(d);
						break;
					case 2:
						d.d_delete();
						break;
					case 3:
						d.d_search();
						break;
					case 4:
						d.d_modify();
						break;
					case 5:
						d.d_display();
						break;
					case 6:
						exit(0);

				       default:
						cout<<"Enter proper option:"<<endl;
				}
			}while(i!=6);

		}

  //--------- End of donor module----------------------------

 //-------------------Receiver module-------------------------


	   void r_add(receiver &r)
		{
		   fstream finout;
		   int n;
		   cout<<"Add receiver"<<endl;
		   finout.open("receiver.txt",ios::app);
		   if(finout.eof()!=0)
		   {
		     cout<<"Unable to open a file"<<endl;
		     exit(1);
		   }
		  else
		   {
		   r.getdata();

		    cout<<"receiver id"<<++r.r_id<<endl;
		    blgr:
		    cout<<"Enter Blood group of receiver:"<<endl;
		    gets(r.bg_gr);
		    if((strcmpi(r.bg_gr,"A+")!=0)&&(strcmpi(r.bg_gr,"A-")!=0) && (strcmpi(r.bg_gr,"B+")!=0) && (strcmpi(r.bg_gr,"B-")!=0) && (strcmpi(r.bg_gr,"AB+")!=0) && (strcmpi(r.bg_gr,"AB-")!=0) && (strcmpi(r.bg_gr,"O+")!=0) && (strcmpi(r.bg_gr,"O-")!=0))
		    {
		      cout<<"invalid blood group"<<endl;
		      goto blgr;
		    }

		    cout<<"Enter quantity of blood received(ml)"<<endl;
		    cin>>r.qty;

		    cout<<"Enter cause:"<<endl;
		    gets(r.cause);
		    finout.clear();
		    finout.seekp(ios::end);
		    finout.write((char*)&r, sizeof(r));
		    finout.close();
		   }
	    }
	 void receiver::r_delete()
	  {
		receiver r1;
	     int no;
	    cout<<"Enter receiver id number to be deleted"<<endl;
	    cin>>no;

	    fstream finout1,finout2;
	    finout1.open("receiver.txt",ios::in);
	    finout2.open("receiver1.txt",ios::out);

	    if(finout1.eof()!=0)
	    {
		cout<<"Unable to open a first file";
		exit(1);
	    }
		if(finout2.eof()!=0)
		{
		  cout<<"Unable to open second file ";
		  exit(1);
		}
		   while(finout1.read((char*)&r1,sizeof(r1)))
		   {
		      if(r1.r_id==no)
			{
			}
		      else
			{
			  finout2.write((char*)&r1,sizeof(r1));
			}
		  }
		finout1.close();
		finout2.close();
		 remove("receiver.txt");
		 rename("receiver1.txt","receiver.txt");

	}

	 void receiver::r_modify()
		{
			receiver r1;
			fstream finout;
			int n,x=0;
			cout<<"Modify Receiver"<<endl;
			finout.open("receiver.txt",ios::in|ios::out);
			if(finout.eof()!=0)
		       {
			    cout<<"Unable to open a file"<<endl;
			    exit(1);
		       }
		     else
		     {
			cout<<"Enter receiver id to be modified"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&r1, sizeof(r1)))
		       {
			if( n == r1.r_id)
			{
			 cout<<"Enter new values\n";
			 r1.getdata();
			 r1.r_id = n;

			 blgr:
			 cout<<"Enter Blood group of receiver:"<<endl;
			 gets(r1.bg_gr);
			 if((strcmpi(r1.bg_gr,"A+")!=0)&&(strcmpi(r1.bg_gr,"A-")!=0) && (strcmpi(r1.bg_gr,"B+")!=0) && (strcmpi(r1.bg_gr,"B-")!=0) && (strcmpi(r1.bg_gr,"AB+")!=0) && (strcmpi(r1.bg_gr,"AB-")!=0) && (strcmpi(r1.bg_gr,"O+")!=0) && (strcmpi(r1.bg_gr,"O-")!=0))
			 {
			   cout<<"invalid blood group"<<endl;
			   goto blgr;
			 }

			 cout<<"Enter quantity of blood received(ml)"<<endl;
			 cin>>r1.qty;

			long location=(x)*sizeof(r1);
			finout.seekp(location);
			finout.write((char*)&r1,sizeof(r1));


			n = -1;
			break;
		      }
		   x++;
		}
		if(n != -1)
			cout<<"Not Found"<<endl;
		x++;
	    }

	 finout.clear();
	 finout.close();
		     }


	     void receiver::r_search()
		{
			receiver r;
			fstream finout;
			int n;
			finout.open("receiver.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			cout<<"Enter receiver id to be search"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&r, sizeof(r)))
			{
				if( n == r.r_id)
				{
				r.putdata();
				n = -1;
				break;
				 }
			}
			if(n != -1)
				cout<<"Not Found"<<endl;

			finout.close();
		     }

	     }


	      void receiver::r_display()
		{
		       receiver r1;
		       fstream finout;
		       finout.open("receiver.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			while(finout.read((char*)&r1, sizeof(r1)))
			{
				r1.putdata();
				cout<<"receiver id:"<<r1.r_id<<endl;
				cout<<"blood group:"<<r1.bg_gr<<endl;
			}

			finout.close();
		     }
		}


//------------------- main function for Receiver--------------------------

		void R_main(receiver &r)
		{
			int i;
			do
			{
				cout<<"1.Add receiver"<<endl;
				cout<<"2.Delete receiver"<<endl;
				cout<<"3.search receiver"<<endl;
				cout<<"4.modify receiver"<<endl;
				cout<<"5.display receiver"<<endl;
				cout<<"6.exit"<<endl;
				cout<<"Enter option"<<endl;
				cin>>i;

				switch(i)
				{
					case 1:
						r_add(r);
						break;
					case 2:
						r.r_delete();
						break;
					case 3:
						r.r_search();
						break;
					case 4:
						r.r_modify();
						break;
					case 5:
						r.r_display();
						break;
					case 6:
						exit(0);

				       default:
						cout<<"Enter proper option:"<<endl;
				}
			}while(i!=6);

		}
//----------------------- End of Receiver module------------------------

//-----------------------Employee module---------------------------------


      void e_add(employee &e)
		{
		   fstream finout;
		   int n;
		   cout<<"Add employee"<<endl;
		   finout.open("employee.txt",ios::app);
		   if(finout.eof()!=0)
		   {
		     cout<<"Unable to open a file"<<endl;
		     exit(1);
		   }
		  else
		   {
		     e.getdata();

		    cout<<"epmloyee id"<<++e.emp_id<<endl;
		    sal:
		    cout<<"Enter salary :"<<endl;
		    cin>>e.salary;
		    if(e.salary<0)
		    {
			cout<<"Invaid.. " <<endl;
			goto sal;
		    }
		    cout<<"Enter dept:"<<endl;
		    gets(e.dept);
		    finout.clear();
		    finout.seekp(ios::end);
		    finout.write((char*)&e, sizeof(e));
		    finout.close();
		   }
	    }
	 void employee::e_delete()
	  {
		employee e1;
	     int no;
	    cout<<"Enter employee id number to be deleted"<<endl;
	    cin>>no;

	    fstream finout1,finout2;
	    finout1.open("employee.txt",ios::in);
	    finout2.open("employee1.txt",ios::out);

	    if(finout1.eof()!=0)
	    {
		cout<<"Unable to open a first file";
		exit(1);
	    }
		if(finout2.eof()!=0)
		{
		  cout<<"Unable to open second file ";
		  exit(1);
		}
		   while(finout1.read((char*)&e1,sizeof(e1)))
		   {
		      if(e1.emp_id==no)
			{
			}
		      else
			{
			  finout2.write((char*)&e1,sizeof(e1));
			}
		  }
		finout1.close();
		finout2.close();
		remove("employee.txt");
		rename("employee1.txt","employee.txt");
	}

	 void employee::e_modify()
		{
			employee e1;
			fstream finout;
			int n,y=0;
			cout<<"Modify Employee"<<endl;
			finout.open("employee.txt",ios::in|ios::out);
			if(finout.eof()!=0)
		       {
			    cout<<"Unable to open a file"<<endl;
			    exit(1);
		       }
		     else
		     {
			cout<<"Enter employee id to be modified"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&e1, sizeof(e1)))
			{
				if( n == e1.emp_id)
				{

			cout<<"Enter new values\n";

		   e1.getdata();
		   e1.emp_id = n;

		    sal:
		    cout<<"Enter salary:"<<endl;
		    cin>>e1.salary;
		    if(e1.salary<0)
		    {
		      cout<<"Invalid.."<<endl;
		      goto sal;
		    }
		    cout<<"Enter dept:"<<endl;
		    gets(e1.dept);

			long location=(y)*sizeof(e1);
			finout.seekp(location);
			finout.write((char*)&e1,sizeof(e1));


				n = -1;
				break;
				 }
				y++;
			}
			if(n != -1)
				cout<<"Not Found"<<endl;
			y++;
		}

			finout.clear();
			finout.close();
		     }


	     void employee::e_search()
		{
			employee e1;
			fstream finout;
			int n;
			finout.open("employee.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			cout<<"Enter employee id to be search"<<endl;
			cin>>n;
			finout.clear();
			finout.seekg(ios::beg);
			while(finout.read((char*)&e1, sizeof(e1)))
			{
				if( n == e1.emp_id)
				{
				e1.putdata();
				n = -1;
				break;
				 }
			}
			if(n != -1)
				cout<<"Not Found"<<endl;

			finout.close();
		     }

	     }


	void employee::e_display()
		{
			employee e1;
			fstream finout;
			int n;
			finout.open("employee.txt",ios::in);
			if(finout.eof()!=0)
			{
			  cout<<"Unable to open a file"<<endl;
			  exit(1);
			}
		       else
		       {
			while(finout.read((char*)&e1, sizeof(e1)))
			{
				e1.putdata();
				cout<<"employee id:"<<e1.emp_id<<endl;
				cout<<"Dept:"<<e1.dept<<endl;
			}

			finout.close();
		     }
		}

//---------------------Main functio for Employee module-------------------

	     void E_main(employee &e)
		{
			int i;
			do
			{
				cout<<"1.Add employee"<<endl;
				cout<<"2.Delete employee"<<endl;
				cout<<"3.search employee"<<endl;
				cout<<"4.modify employee"<<endl;
				cout<<"5.display employee"<<endl;
				cout<<"6.exit"<<endl;
				cout<<"Enter option"<<endl;
				cin>>i;

				switch(i)
				{
					case 1:
						e_add(e);
						break;
					case 2:
						e.e_delete();
						break;
					case 3:
						e.e_search();
						break;
					case 4:
						e.e_modify();
						break;
					case 5:
						e.e_display();
						break;
					case 6:
						exit(0);

				       default:
						cout<<"Enter proper option:"<<endl;
				}
			}while(i!=6);

		}

//--------------------- End of Employee module------------------------------


//-----------------------Enquiry module------------------------------------


void enquiry::enq()
      {
	    do
	    {

	      cout<<"ENQUIRY COUNTER"<<endl;
	      cout<<"-----------------"<<endl;
	      cout<<"you want to enquire about ..."<<endl;
	      cout<<"1.Donor"<<endl;
	      cout<<"2.Receiver"<<endl;
	      cout<<"3.Employee"<<endl;
	      cout<<"4.exit"<<endl;
	      cout<<"-->"<<endl;
	      cin>>ch;

	      switch(ch)
	      {
		case 1:
			d_search();
			break;
		case 2:
			r_search();
			break;
		case 3:
			e_search();
			break;
		case 4:
			exit(0);
		default:
			cout<<"Please enter properly"<<endl;
	      }
	  }while(ch!=4);
    }


//----------------------- void main-------------------------------------


  void main()
 {
       int i;
       clrscr();
	do
	{
		cout<<"1.Receptionist/Enquiry counter"<<endl;
		cout<<"2.Donor"<<endl;
		cout<<"3.Rceiever"<<endl;
		cout<<"4.Employee"<<endl;
		cout<<"5.Search by Group"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter option"<<endl;
		cin>>i;
		clrscr();
		switch(i)
		{
			case 1:
				enquiry obj;
				obj.enq();
				break;
			case 2:
				donor d;
			       D_main(d);
				break;
			case 3:
				receiver r;
				R_main(r);
				break;
			case 4:
				employee e;
				E_main(e);
				break;
			case 5: donor d1;
				d1.d_group_search();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"Enter proper option:"<<endl;
		 }
	}while(i!=6);
  }
