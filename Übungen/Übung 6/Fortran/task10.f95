program task10
implicit none

! variable decleration
integer :: s1, i, j, k
real, allocatable,dimension(:,:):: A, B, C
real :: start, finish

! read in shape
print *, 'Shape of matrix: '
read *,s1

call cpu_time(start)

allocate(A(s1, s1))
allocate(B(s1, s1))
allocate(C(s1 ,s1))


do i=1, s1
  do j=1, s1
    A(i, j) = (i-1)*s1 + (j-1)
    B(i, j) = (i-1)*s1 + (j-1)
    C(i, j) = 0
  end do
end do

do i=1, s1
  do j=1, s1
    do k=1, s1
    	C(i, j) = C(i, j) + (A(i, k) * B(j, k))
	end do
  end do
  if(modulo(i, s1 / 10) == 0) print *, int(real(i*100) / real(s1)), "%"
end do

call cpu_time(finish)


! print *, A

print *, "Time:", finish - start, "s"

deallocate(A)
deallocate(B)
deallocate(C)

end program task10