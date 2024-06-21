

echo $1 $2 $3 $4 $5

if [ "$1" == "-h" ] ; then
 echo "Usage: $0 d m s"
   echo "-d: display only a brief description of the specified command."
   echo "-m: organize the available information just as the man command does."
   echo "-s: display the command syntax of the specified command."
     exit 0
fi

if [ "$5" == "-C" ] ; then
    rm --rep$i;
fi

if ! [[ $2 =~ ^[0-9]+$ ]]; then
    echo "$2 n'est pas bon" 
    exit 1 
fi
if ! [[ $4  =~ ^[0-9]+$ ]]; then
   echo  "$4 n'est pas bon"; 
   exit 1
fi

# indentation 
#création des répertoires et les fichers
if ! [ "$5" == "-c" ]
  then
    for ((i=1; i<=$2;i++));
      do mkdir rep$i;
       for ((y=1; y<=$4; y++))
          do 
            touch rep$i/file$y;
          done;
       done

     else [ "$5" == "-c" ]
     
    #supppression des répertoires rep
    
        for ((i=1;i<=$2;i=i+1));
          
           do 
            rm -Rf $1$i;
           done
  

fi