
{
int x = -12, y;
y = absolute(x);
printf("The absolute value of %d is %d\n", x, y);
}
int absolute(int num)
{
if (num < 0)
return (-num);
else
return (num);
}