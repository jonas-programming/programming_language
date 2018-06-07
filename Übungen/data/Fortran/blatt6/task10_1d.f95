program task10
implicit none

! variable decleration
integer :: s1, i, j, k
real, allocatable,dimension(:):: A, B, C
real :: start, finish

! read in shape
print *, 'Shape of matrix: '
read *,s1

call cpu_time(start)

allocate(A(s1*s1))
allocate(B(s1*s1))
allocate(C(s1*s1))

print *, "Allocation done!"

do i=0, s1-1
  do j=0, s1-1
    A(i*s1 + j + 1) = i*s1 + j + 1
    B(i*s1 + j + 1) = i*s1 + j + 1
    C(i*s1 + j + 1) = 0
  end do
end do

print *, "Filling done!"

do i=0, s1-1
  do j=0, s1-1
    do k=0, s1-1
    	C(i*s1 + j + 1) = C(i*s1 + j + 1) + (A(i*s1 + k + 1) * B(i*s1 + k + 1))
	end do
  end do
  if(modulo(i, s1 / 100) == 0) print *, int(real(i*100) / real(s1)), "%"
end do

call cpu_time(finish)


! print *, A

print *, "Time:", finish - start, "s"

deallocate(A)
deallocate(B)
deallocate(C)

end program task10