void main()
{
 int cnt=0;
  
 trisb.f0=1;
 portb=0;
  
 trisd=0x00;
 portd=0x00;
  
 for(;;)
 {
  if(portb.f0==1)
  {
  cnt++;
    
  while(portb.f0==1);
    
  if(cnt==7)
  {
  cnt=1;
  }
  
  }

  if(cnt==1)
  {
  portd.f0=0;
  portd.f1=0;
  portd.f2=1;
  portd.f3=0;
  portd.f4=0;
  portd.f5=0;
  portd.f6=0;
 }

  if(cnt==2)
  {
  portd.f0=1;
  portd.f1=1;
  portd.f2=0;
  }

  if(cnt==3)
  {
  portd.f2=1;
  }

  if(cnt==4)
  {
  portd.f0=0;
  portd.f1=0;
  portd.f2=0;
  portd.f3=1;
  portd.f4=1;
  portd.f5=1;
  portd.f6=1;
  }

   if(cnt==5)
  {
  portd.f2=1;
  }

   if(cnt==6)
  {
  portd.f2=0;
  portd.f0=1;
  portd.f1=1;
  }
}
}
