void concate(char *con,char **str,int size){
	int i;
	for(i=0;i<size;i++){
		while(*str[i]!=10 && *str[i]!='\0'){
			*con=*str[i];
			con++;
			str[i]++;
		}
	}
	*con='\0';
}
int getCompileMethod(char *arg1,char *arg2){
	char a1,a2,b1,b2;
	while(*arg1!=10 && *arg1!='\0')
		arg1++;
	a1=*(arg1-2);
	a2=*(arg1-1);
	while(*arg2!=10 && *arg2!='\0')
		arg2++;
	b1=*(arg2-2);
	b2=*(arg2-1);
	if(a1=='.' && a2=='c' && b1=='.' && b2=='o')
		return 1;
	else if(a1=='.' && a2=='o' && b1!='.')
		return 2;
	else if(a1=='.' && a2=='c' && b1!='.')
		return 3;
	else 
		return -1;
}
int main(int argc,char *argv[]){
	char cmd[1000];
	if(argc!=3)
	{
		puts("Error: Argument must contain name of program to be processed");
		puts("And its output extension ONLY!!!");
		return 0;
	}
	char *openCV_location="<enter the location of your openCV directory>";//for example "C:/programs"

	int compile=getCompileMethod(argv[1],argv[2]);
	if(compile==1){
		char *gcc_console1[]={"gcc -c ",argv[1]," -o ",argv[2]," -I\"",openCV_location,"/opencv/build/include\" -I\"",openCV_location,"/opencv/build/include/opencv\""};
		concate(cmd,gcc_console1,9);
	}
	else if(compile==2){
		char *gcc_console2[]={"gcc ",argv[1]," -o ",argv[2]," -L\"",openCV_location,"/opencv/build/x86/vc12/bin\" -lopencv_calib3d249 -lopencv_calib3d249d -lopencv_contrib249 -lopencv_contrib249d -lopencv_core249 -lopencv_core249d -lopencv_features2d249 -lopencv_features2d249d -lopencv_ffmpeg249 -lopencv_flann249 -lopencv_flann249d -lopencv_gpu249 -lopencv_gpu249d -lopencv_highgui249 -lopencv_highgui249d -lopencv_imgproc249 -lopencv_imgproc249d -lopencv_legacy249 -lopencv_legacy249d -lopencv_ml249 -lopencv_ml249d -lopencv_nonfree249 -lopencv_nonfree249d -lopencv_objdetect249 -lopencv_objdetect249d -lopencv_ocl249 -lopencv_ocl249d -lopencv_photo249 -lopencv_photo249d -lopencv_stitching249 -lopencv_stitching249d -lopencv_superres249 -lopencv_superres249d -lopencv_video249 -lopencv_video249d -lopencv_videostab249 -lopencv_videostab249d"};
		concate(cmd,gcc_console2,7);
	}		
	else if(compile==3){
		char *gcc_console3[]={"gcc ",argv[1]," -o ",argv[2]," -I\"",openCV_location,"/opencv/build/include\" -I\"",openCV_location,"/opencv/build/include/opencv\" -L\"",openCV_location,"/opencv/build/x86/vc12/bin\" -lopencv_calib3d249 -lopencv_calib3d249d -lopencv_contrib249 -lopencv_contrib249d -lopencv_core249 -lopencv_core249d -lopencv_features2d249 -lopencv_features2d249d -lopencv_ffmpeg249 -lopencv_flann249 -lopencv_flann249d -lopencv_gpu249 -lopencv_gpu249d -lopencv_highgui249 -lopencv_highgui249d -lopencv_imgproc249 -lopencv_imgproc249d -lopencv_legacy249 -lopencv_legacy249d -lopencv_ml249 -lopencv_ml249d -lopencv_nonfree249 -lopencv_nonfree249d -lopencv_objdetect249 -lopencv_objdetect249d -lopencv_ocl249 -lopencv_ocl249d -lopencv_photo249 -lopencv_photo249d -lopencv_stitching249 -lopencv_stitching249d -lopencv_superres249 -lopencv_superres249d -lopencv_video249 -lopencv_video249d -lopencv_videostab249 -lopencv_videostab249d"};
		concate(cmd,gcc_console3,11);
	}
	else{
		puts("Error: Incorrect output file format\n Compilation terminated");
	}
	system(cmd);
}
