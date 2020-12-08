#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

using namespace std;

__device__ int add_one(int a) {

	return a + 1;
}

__global__ void show(int *a) {

	for (int i = 0; i < 10; i++) {

		//a[i] = add_one(a[i]);
		printf(" %d", a[i]);
	}
	printf("\n");
}

__global__ void changeValue(int *a) {

	for (int i = 0; i < 10; i++) {

		a[i] = 100;
	}
}

int main() {

	int cpu_int[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	int *gpu_int;

	//在GPU上分配空间
	cudaMalloc((void**)&gpu_int, 10 * sizeof(int));
	show << <1, 1 >> > (gpu_int);

	//初始化其值
	cudaMemset(gpu_int, 0, 10 * sizeof(int));
	show<< <1, 1 >> > (gpu_int);

	//将cpu_int赋值给gpu_int
	cudaMemcpy(gpu_int, cpu_int, 10 * sizeof(int), cudaMemcpyHostToDevice);
	show << <1, 1 >> > (gpu_int);

	//改变gpu_int的值
	changeValue << <1, 1 >> >(gpu_int);
	show << <1, 1 >> > (gpu_int);


	cudaMemcpy(cpu_int, gpu_int, 10 * sizeof(int), cudaMemcpyDeviceToHost);
	printf("----------华丽的分割线----------");
	for (int i = 0; i < 10; i++) {


		printf("%d", cpu_int[i]);
	}



	cudaFree(gpu_int);


	getchar();
	return 0;
}