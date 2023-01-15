        subroutine idz_sfrmi(l,m,n,w)
c
c       initializes data for the routine idz_sfrm.
c
c       input:
c       l -- length of the transformed (output) vector
c       m -- length of the vector to be transformed
c
c       output:
c       n -- greatest integer expressible as a positive integer power
c            of 2 that is less than or equal to m
c       w -- initialization array to be used by routine idz_sfrm
c
c
c       glossary for the fully initialized w:
c
c       w(1) = m
c       w(2) = n
c       w(3) is unused
c       w(4:3+m) stores a permutation of m objects
c       w(4+m:3+m+l) stores the indices of the l outputs which idz_sfft
c                    calculates
c       w(4+m+l) = address in w of the initialization array
c                  for idz_random_transf
c       w(5+m+l:int(w(4+m+l))-1) stores the initialization array
c                                for idz_sfft
c       w(int(w(4+m+l)):19*m+70) stores the initialization array
c                                for idz_random_transf
c
c
c       _N.B._: n is an output of the present routine;
c               this routine changes n.
c
c
        implicit none
        integer l,m,n,idummy,nsteps,keep,lw,ia
        complex*16 w(21*m+70)
c
c
c       Find the greatest integer less than or equal to m
c       which is a power of two.
c
        call idz_poweroftwo(m,idummy,n)
c
c
c       Store m and n in w.
c
        w(1) = m
        w(2) = n
        w(3) = 0
c
c
c       Store random permutations of m and n objects in w.
c
        call id_randperm(m,w(4))
        call id_randperm(n,w(4+m))
c
c
c       Store the address within w of the idz_random_transf_init
c       initialization data.
c
        ia = 5+m+l+2*l+15+3*n
        w(4+m+l) = ia
c
c
c       Store the initialization data for idz_sfft in w.
c
        call idz_sffti(l,w(4+m),n,w(5+m+l))
c
c
c       Store the initialization data for idz_random_transf_init in w.
c
        nsteps = 3
        call idz_random_transf_init(nsteps,m,w(ia),keep)
c
c
c       Calculate the total number of elements used in w.
c
        lw = 4+m+l+2*l+15+3*n + 3*nsteps*m+2*m+m/4+50
c
        if(19*m+70 .lt. lw) then
          call prinf('lw = *',lw,1)
          call prinf('19m+70 = *',19*m+70,1)
          stop
        endif
c
c
        return
        end
c
c
c
c
