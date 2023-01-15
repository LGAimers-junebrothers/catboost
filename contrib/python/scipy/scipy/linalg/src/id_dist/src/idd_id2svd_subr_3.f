        subroutine idd_matmultt(l,m,a,n,b,c)
c
c       multiplies a and b^T to obtain c.
c
c       input:
c       l -- first dimension of a and c
c       m -- second dimension of a and b
c       a -- leftmost matrix in the product c = a b^T
c       n -- first dimension of b and second dimension of c
c       b -- rightmost matrix in the product c = a b^T
c
c       output:
c       c -- product of a and b^T
c
        implicit none
        integer l,m,n,i,j,k
        real*8 a(l,m),b(n,m),c(l,n),sum
c
c
        do i = 1,l
          do k = 1,n
c
            sum = 0
c
            do j = 1,m
              sum = sum+a(i,j)*b(k,j)
            enddo ! j
c
            c(i,k) = sum
c
          enddo ! k
        enddo ! i
c
c
        return
        end
c
c
c
c
