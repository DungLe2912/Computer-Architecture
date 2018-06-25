.data
	menu_tbl: .asciiz "\n==================== MENU ====================\n\n  1. Nhap mang\n  2. Xuat mang\n  3. Liet ke so nguyen to trong mang\n  4. Liet ke so hoan thien trong mang\n  5. Tinh tong cac so chinh phuong trong mang\n  6. Tinh trung binh cong cac so doi xung trong mang\n  7. Tim gia tri lon nhat trong mang\n  8. Sap xep mang tang dan theo `Selection sort`\n  9. Sap xep mang giam dan theo `Bubble sort`\n\n 10. Thoat\n\n=============================================="
	menu_err: .asciiz "\n\nLUA CHON: "

	funct1_msg1: .asciiz "\nSo luong phan tu cua mang: "
	funct1_msg2: .asciiz "a["
	funct1_msg3: .asciiz "] = "
	
	funct2_msg1: .asciiz "\nXuat Mang: "
	funct2_msg2: .asciiz "\nMang khong co phan tu nao ca."
	funct3_msg1:.asciiz"\nCac so nguyen to trong mang:  "
	funct4_msg1:.asciiz"\nCac so hoan thien trong mang: "
	funct5_msg1:.asciiz"\nTong cac so chinh phuong trong mang: "
	funct6_msg1: .asciiz "\nTrung binh cong cac so Doi Xung trong mang: "
	funct7_msg: .asciiz "Gia tri lon nhat trong mang: "
	funct8_msg: .asciiz "Sap xep tang dan Selection Sort: "
	funct9_msg: .asciiz "Sap xep giam dan Bubble Sort: "
	
	arr_size: .word 0
	arr_data: .space 400
	
.text
	.globl main

# ---

main: # Ngo vao chuong trinh

	# Xuat menu_tbl.
	li $v0, 4
	la $a0, menu_tbl
	syscall

	# Nhap lua chon
	main.choice:

		# Xuat menu_err.
		li $v0, 4
		la $a0, menu_err
		syscall
	
		# Nha^.p lu+.a cho.n.
		li $v0, 5
		syscall
		move $s7, $v0 # cur_funct: .space 4 # `current_selected_functionality`.

		# Re den 1 chuc nang
		beq $s7, 1, funct_1 #Nhap mang
		beq $s7, 2, funct_2 # Xuat mang
		beq $s7, 3, funct_3 # Liet ke cac so nguyen to trong mang
		beq $s7, 4, funct_4 #Liet ke cac so hoan thien trong mang	
		beq $s7, 5, funct_5 # Tinh tong cac so chinh phuong trong mang
		beq $s7, 6, funct_6 # Tinh tbc cac so doi xung trong mang
		beq $s7, 7, funct_7 # Tim gia tri lon nhat trong mang
		beq $s7, 8, funct_8 # Sap xep mang tang dan theo Selection sort`.
		beq $s7, 9, funct_9 # ap xep mang gi?m dan theo `Bubble sort`.
		beq $s7, 10, exit # Ket thuc chuong trinh
		
		# Xuat menu_error
		li $v0, 4
		la $a0, menu_err # Tong bao nhap lai
		syscall

		j main.choice # Nhap lai

# ---

funct_1: # Nhap mang.

	# Xuat funct1_msg1.
	li $v0, 4
	la $a0, funct1_msg1
	syscall
	
	# Nhap so nguyen.
	li $v0, 5
	syscall
	
	# Save vao arr_size`.
	sw $v0, arr_size
	
	# Loai arr_size vao $s1
	lw $s1, arr_size
	
	# ---
	
	# Khoi tao vong lap
	li $t0, 0 # i = 0.
	la $s0, arr_data # Load dia chi cua mang vao $s0.

	funct_1.input_loop: # Lap nhap.
	
		# Xuat funct1_msg2.
		li $v0, 4
		la $a0, funct1_msg2
		syscall
		
		# Xuat chi so i.
		li $v0, 1
		move $a0, $t0
		syscall
		
		# Xuat `funct1_msg3`.
		li $v0, 4
		la $a0, funct1_msg3
		syscall

		# Nhap so nguyen.
		li $v0, 5
		syscall
		
		# Luu a[i] va`o ($s0).
		sw $v0, ($s0)
	
		# Tang dia chi mang
		addi $s0, $s0, 4
		
		# Tang chi so i
		add $t0, $t0, 1
		
		# Kiem tra dieu kien lap
		slt $t1, $t0, $s1 # i < n
		beq $t1, 1, funct_1.input_loop

	# ---

	j main.choice # Lua chon chuc nang ke tiep trong chuong trinh

# ---

funct_2: # Xua^'t ma?ng.

	# Kiem tra mang co rong hay khong.
	bne $s1, $0, funct_2.output_arrary
	
	# Xuat funct2_msg2`.
	li $v0, 4
	la $a0, funct2_msg2 # Mang khong co phan tu nao ca.
	syscall

	# ---

	j main.choice # Lua chon chuc nang ke tiep trong chuong trinh.
		
	# ---
	
	funct_2.output_arrary: # Xuat toan bo phan tu cua mang.
	
		# Xuat funct2_msg1`.
		li $v0, 4
		la $a0, funct2_msg1
		syscall
		
		# Khoi tao vo`ng lap.
		li $t0, 0
		la $s0, arr_data

		funct_2.output_loop:
		
			# Xuat `a[i]`.
			li $v0, 1
			lw $a0, ($s0)
			syscall			
		
			# Xuat khoang trang.
			li $v0, 11
			li $a0, 32 # 32 = ascii_code(SPACE_CHAR).
			syscall
			
			# Ta(ng ddi.a chi? ma?ng.
			addi $s0, $s0, 4
			
			# Ta(ng chi? so^' `i\`.
			addi $t0, $t0, 1
			
			# Kiem tra dieu kien lap.
			slt $t1, $t0, $s1 # i < n.
			beq $t1, 1, funct_2.output_loop

			# ---

			j main.choice # Lua chon chuc nang ke tiep trong chuong trinh

# ---

funct_3: # Liet ke cac so nguyen to trong mang

	
#Liet ke so nguyen to
	#xuat tb6
	li $v0,4
	la $a0,funct3_msg1
	syscall	
	
	jal _SoNguyenTo

	j main.choice

_SoNguyenTo:
#dau thu duc
#Backup thanh ghi
	addi $sp,$sp,-20
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)
	sw $t1,12($sp)
	sw $s1,16($sp)

#than thu tuc
	la $s0,arr_data #load dia chi phan tu dau cua mang vao thanh ghi $s0
	li $t0,0 #i = 0
_SoNguyenTo.Lap:
	lw $t1,($s0)
	#kiem tra 1 va 2
	#1 va 2 khong phai la so ngto nen bo qua
	beq $t1,1,_SoNguyenTo.Tangi
	beq $t1,2,_SoNguyenTo.Tangi
	move $a0,$t1
	jal _KTNT  #goi ham kiem tra so nguyen to
	#luu ket qua vao $s1
	move $s1,$v0

	#kiem tra ket qua
	#neu so luong uoc so bang 1 (ngoai tru no) thi la songuyento
	beq $s1,1, _SoNguyenTo.Xuat
	j _SoNguyenTo.Tangi
_SoNguyenTo.Xuat:
	li $v0,1
	move $a0,$t1
	syscall

	li $v0,11
	la $a0,32
	syscall
_SoNguyenTo.Tangi:
	addi $t0,$t0,1
	addi $s0,$s0,4
	#kiem tra i (i<n)
	lw $s3,arr_size #load so phan tu cua mang vao thanh ghi $s3
	slt $s1,$t0,$s3 #neu vi tri phan tu hien tai nho hon so phtu cua mang thi tiep tuc lap
	beq $s1,1,_SoNguyenTo.Lap

	j _SoNguyenTo.KetThuc

#cuoi thu tuc
_SoNguyenTo.KetThuc:
#restore thanh ghi
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	lw $t1,12($sp)
	lw $s1,16($sp)
	addi $sp,$sp,20
	jr $ra
#ham xu li so nguyen to
_KTNT:
	# Khai bao kich thuoc `stack`
	addi $sp, $sp, -16
	# Backup cac thanh ghi.
	sw $ra, ($sp)
	sw $s0, 4($sp)
	sw $t0, 8($sp)
	sw $t1, 12($sp)
	

#Than thu tuc
	# S = 0
	li $s0, 0
	# Khoi tao vong lap.
	# i = 1
	li $t0,1
_KTNT.Lap:
	sub $t1, $t0, $a0 # t1 = i - n
	bltz $t1, _KTNT.KTUS # t1 < 0 <=> i < n
	j _KTNT.KTLap

_KTNT.KTUS:
	# Kiem tra `i` la uoc so cua `n`?
	div $a0, $t0  
	mfhi $t1 # Lay phan du t1 = n % i
	beq $t1, 0, _KTNT.TongUS  # Neu phan du t1 = 0 thi tinh so cac uoc so.
	j _KTNT.Tangi

_KTNT.TongUS:
	addi $s0, $s0, 1 #tinh so luong uoc so

_KTNT.Tangi:

	addi $t0, $t0, 1
	j _KTNT.Lap

_KTNT.KTLap:
	beq $s0,1, _KTNT.Return1
	# reuturn 0
	li $v0, 0
	j _KTNT.KetThuc

_KTNT.Return1:
	li $v0, 1

_KTNT.KetThuc:
# Cuoi thu tuc.
	# Restore cac thanh ghi
	lw $ra, ($sp)
	lw $s0, 4($sp)
	lw $t0, 8($sp)
	lw $t1, 12($sp)

	# Xoa stack
	addi $sp, $sp, 16
	
	# Tra ve.
	jr $ra

# ---

funct_4: # Liet ke cac so hoan thien trong mang
	
#xuat tb
	li $v0,4
	la $a0,funct4_msg1
	syscall	
	
	jal _SoHoanThien
	j  main.choice
#
_SoHoanThien:
#dau thu duc
	addi $sp,$sp,-20
	sw $ra,($sp)
	sw $s0,4($sp)
	sw $t0,8($sp)
	sw $t1,12($sp)
	sw $s1,16($sp)

#than thu tuc
	la $s0,arr_data
	li $t0,0 #i = 0
_SoHoanThien.Lap:
	lw $t1,($s0) #load dia chi phan tu dau tien vao thanh ghi $t1
	move $a0,$t1
	jal _KTHT
	#luu ket qua vao $s1
	move $s1,$v0
	#kiem tra ket qua
	beq $s1,1, _SoHoanThien.Xuat
	j _SoHoanThien.Tangi
_SoHoanThien.Xuat:
	li $v0,1
	move $a0,$t1
	syscall

	li $v0,11
	la $a0,32
	syscall
_SoHoanThien.Tangi:
	addi $t0,$t0,1
	addi $s0,$s0,4
	#kiem tra i (i<n)
	lw $s3,arr_size
	slt $s1,$t0,$s3
	beq $s1,1,_SoHoanThien.Lap
	j _SoHoanThien.KetThuc

#cuoi thu tuc
_SoHoanThien.KetThuc:
	lw $ra,($sp)
	lw $s0,4($sp)
	lw $t0,8($sp)
	lw $t1,12($sp)
	lw $s1,16($sp)
	addi $sp,$sp,20
	jr $ra
_KTHT:
	# Khai bao kich thuoc `stack`
	addi $sp, $sp, -16
	# Backup cac thanh ghi.
	sw $ra, ($sp)
	sw $s0, 4($sp)
	sw $t0, 8($sp)
	sw $t1, 12($sp)
	

#Than thu tuc
	# S = 0
	li $s0, 0
	# Khoi tao vong lap.
	# i = 1
	li $t0,1

_KTHT.Lap:
	sub $t1, $t0, $a0 # t1 = i - n
	bltz $t1, _KTHT.KTUS # t1 < 0 <=> i < n
	j _KTHT.KTLap

_KTHT.KTUS:
	# Kiem tra `i` la uoc so cua `n`?
	div $a0, $t0  
	mfhi $t1 # Lay phan du t1 = n % i
	beq $t1, 0, _KTHT.TongUS  # Neu phan du t1 = 0 thi tinh tong cac uoc so.
	j _KTHT.Tangi

_KTHT.TongUS:
	add $s0, $s0, $t0

_KTHT.Tangi:

	addi $t0, $t0, 1
	j _KTHT.Lap

_KTHT.KTLap:
	beq $s0, $a0, _KTHT.Return1
	# reuturn 0
	li $v0, 0
	j _KTHT.KetThuc

_KTHT.Return1:
	li $v0, 1

_KTHT.KetThuc:
# Cuoi thu tuc.
	# Restore cac thanh ghi
	lw $ra, ($sp)
	lw $s0, 4($sp)
	lw $t0, 8($sp)
	lw $t1, 12($sp)

	# Xoa stack
	addi $sp, $sp, 16
	
	# Tra ve.
	jr $ra
	
# ---

funct_5: # Tinh tong cac so chinh phuong trong mang

	
	# Vie^'t pha^`n ca`i dda(.t ha`m ta.i dda^y.
	# ...	
TongSoChinhPhuong:
	#xuat tb9
	li $v0,4
	la $a0,funct5_msg1
	syscall	
	jal _TongSoChinhPhuong

	j  main.choice
_TongSoChinhPhuong:
#dau thu tuc 
	addi $sp,$sp,-28
	sw $ra,($sp)
	sw $t0,4($sp)
	sw $t1,8($sp)
	sw $s0,12($sp)
	sw $s1,16($sp)
	sw $t2,20($sp)
	sw $s3,24($sp)
#than thu tuc
	li $t0,0 #i = 0
	li $s1,0 #sum = 0
	la $s0, arr_data

_TongSoChinhPhuong.Lap:
	lw $t1,($s0)
	move $a0,$t1
	jal _KTCP
	#luu ket qua vao $t2
	move $t2,$v0

	#kiem tra ket qua
	beq $t2,1, _TongSoChinhPhuong.Tong
	j _TongSoChinhPhuong.Tangi

_TongSoChinhPhuong.Tong:
	add $s1,$s1,$t1
_TongSoChinhPhuong.Tangi:
	addi $t0,$t0,1
	addi $s0,$s0,4
	#kiem tra i (i<n)
	lw $s3,arr_size
	slt $t2,$t0,$s3
	beq $t2,1,_TongSoChinhPhuong.Lap

	#Xuat ket qua
	li $v0,1
	move $a0,$s1
	syscall

	j _TongSoChinhPhuong.KetThuc

#cuoi thu tuc
_TongSoChinhPhuong.KetThuc:
	lw $ra,($sp)
	lw $t0,4($sp)
	lw $t1,8($sp)
	lw $s0,12($sp)
	lw $s1,16($sp)
	lw $t2,20($sp)
	sw $s3,24($sp)
	addi $sp,$sp,28
	jr $ra

# ---Ham kiem tra so chinh phuong

_KTCP:
	# Khai bao kich thuoc `stack`
	addi $sp, $sp, -16
	# Backup cac thanh ghi.
	sw $ra, ($sp)
	sw $s0, 4($sp)
	sw $t0, 8($sp)
	sw $t1, 12($sp)
	

#Than thu tuc
	# S = 0
	#li $s0, 0
	# Khoi tao vong lap.
	# i = 1
	li $t0,1
	move $s0,$a0
_KTCP.Lap:
	sub $t1, $t0, $a0 # t1 = i - n
	bltz $t1, _KTCP.KTUS # t1 < 0 <=> i < n
	j _KTCP.KTLap

_KTCP.KTUS:
	mult $t0,$t0 #tinh i^2
	mflo $t1
	beq $s0,$t1, _KTCP.Return1 #ket thuc va tra ve 1 neu n=i^2
	slt $t2,$s0,$t1
	beq $t2,0,_KTCP.Tangi
	#Return 0
	li $v0,0
	j _KTCP.KetThuc


_KTCP.Tangi:

	addi $t0, $t0, 1
	j _KTCP.Lap

_KTCP.KTLap:
	beq $s0,1, _KTCP.Return1
	# reuturn 0
	li $v0, 0
	j _KTCP.KetThuc

_KTCP.Return1:
	li $v0, 1

_KTCP.KetThuc:
# Cuoi thu tuc.
	# Restore cac thanh ghi
	lw $ra, ($sp)
	lw $s0, 4($sp)
	lw $t0, 8($sp)
	lw $t1, 12($sp)

	# Xoa stack
	addi $sp, $sp, 16
	
	# Tra ve.
	jr $ra
#-------Ham kiem tra mot so la so doi xung------
_laSoDoiXung:
	#Khai bao kich thuoc stack
	addi $sp,$sp,-24
	
	#Backup thanh ghi
	sw $ra,($sp)
	sw $a0,4($sp)
	sw $a0,8($sp)
	sw $s0,12($sp)
	sw  $s1,20($sp)
	sw $s2,16($sp)
#Than thu tuc:
	#khoi tao vong lap
	li $s0,	0 #s=0
	li $s1,10 #s1=10
_laSoDoiXung.Lap:
	mult $s0,$s1
	mflo $s0 #s0=s0*10
	div $a0,$s1
	mfhi $s2 #s2= a0%10
	add $s0,$s0,$s2 #s0=s0+s2
	mflo $a0 #a0=s0/10
	bne $a0,0,_laSoDoiXung.Lap #neu a0!=0 -> l?p
	lw $a0,8($sp) 
	beq $a0,$s0,_laSoDoiXung.return1#a0= s0 -> la so doi xung
	bne $a0,$s0,_laSoDoiXung.return0 #khong la so doi xung
	
_laSoDoiXung.return0:
	li $v0,0
	j _laSoDoiXung.ketThuc
_laSoDoiXung.return1:
	li $v0,1
	j _laSoDoiXung.ketThuc
_laSoDoiXung.ketThuc:
	lw $ra,($sp)
	lw $a0,4($sp)
	lw $s0,12($sp)
	lw $s2,16($sp)
	lw  $s1,20($sp)
	addi $sp,$sp,24
	jr $ra

funct_6: # Tinh TBC cac so doi xung trong mang

	# Truye^`n tham so^' cho ha`m.
	# ... truy?n vào
	li $v0,4
	la $a0,funct6_msg1
	syscall
	la $a0,arr_data
	move $a1,$s1
	jal _tinhTBCSoDoiXung
	move $t0,$v0
	li $v0,1
	move $a0,$t0
	syscall
	
	
	# ---

	# Lu+.a cho.n chu+'c na(ng ke^' tie^'p trong chu+o+ng tri`nh.	
	j main.choice

	# --
	
	# Vie^'t pha^`n ca`i dda(.t ha`m ta.i dda^y.
	_tinhTBCSoDoiXung:
#Khai bao kich thuoc stack
	addi $sp,$sp,-20
	#Backup thanh ghi
	sw $ra,($sp)
	sw $a0,4($sp)
	sw $s2,12($sp)
	sw $s0,16($sp)
	sw $a1,8($sp)
#Than thu tuc:
	move $s0,$a0
	li $t0,0
	li $s2,0
	li $t3,0
_tinhTBCSoDoiXung.Lap:
	lw $t2,($s0)
	move $a0,$t2
	jal _laSoDoiXung #kiem tra kq co phai la so doi xung khong
	move $t1,$v0 #lay kq tra ve luu vao $t1
	move $t2,$a0
	beq $t1,1,_tinhTBCSoDoiXung.Tong #t1=1 (là so doi xung thi cong)
_tinhTBCSoDoiXung.Lap_1:
	addi $s0,$s0,4 #tãng ð?a ch? s0
	addi $t0,$t0,1 #tãng t0 lên 1
	slt $t2, $t0, $a1  #kiem tra t0<a1 hay không
        beq $t2,1, _tinhTBCSoDoiXung.Lap #neu t0<a1 lap
	#ket thuc
	beq $t3,0,_tinhTBCSoDoiXung.KhongCoSDX #không có so ðoi xung nào
	div $s2,$t3  
	mflo $t3 #lay ket qua chia s2 cho t3
	move $v0,$t3 #luu ket qua tra ve vào v0
	j _tinhTBCSoDoiXung.KetThuc
_tinhTBCSoDoiXung.Tong:
	add $s2,$s2,$t2 #s2=s2+t2
	addi $t3,$t3,1 #tang t3 len 1
	j _tinhTBCSoDoiXung.Lap_1
_tinhTBCSoDoiXung.KhongCoSDX:
	li $v0,0
	j _tinhTBCSoDoiXung.KetThuc
_tinhTBCSoDoiXung.KetThuc:
	lw $a0,4($sp)
	lw $a1,8($sp)
	lw $s2,12($sp)
	lw $s0,16($sp)
	lw $ra,($sp)
	addi $sp,$sp,20
	jr $ra
	# ...	

# ---

funct_7: # Tim gia tri lon nhat trong mang

	# Truye^`n tham so^' cho ha`m.
	#truyen tham so cho ham _LapTimMax
	la $s0,arr_data
	lw $a0,arr_size
	# goi ham
	jal _TimMax
	
	# La^'y ke^'t qua? tra? ve^`.
	move $s3, $v0
	
	# Xua^'t `funct7_msg`.
	li $v0, 4
	la $a0, funct7_msg
	syscall
	
	# Xua^'t gia' tri. ca^`n ti`m.
	li $v0, 1
	move $a0, $s3
	syscall

	# ---

	# Lua chon chuc nang ke tiep trong chuong trinh.	
	j main.choice

	# ---

	# Cai dat ha`m ti`m gia' tri lon nhat trong mang.
	
		# Dau thu tuc.
		#=====Dau thu tuc =======
	_TimMax:
		#khai bao kich thuoc stack
		addi $sp,$sp,-28
		#backup cac thanh ghi
		sw $ra,($sp)
		sw $t0,4($sp)
		sw $t1,8($sp)
		sw $s1,12($sp)
		sw $s2,16($sp)
		sw $s3,20($sp)
		sw $s4,24($sp)
			
		# Tha^n thu? tu.c.
			
#Than thu tuc
   	#Lay tham so a0
	move $s1, $a0 # chua n
	move $s2, $s0	# chua dia chi phan tu dau mang
	#Khoi tao vong lap
	
	lw $s3,($s2)	#Gia tri a[0]
	li $t0,0 # i = 1

_LapTimMax:
	#tang i
	addi $t0,$t0,1
	#tang dia chi mang
	addi $s2,$s2,4

	#Lay gia tri a[i]
	lw $s4,($s2)
	
	# so sanh a[i] hien tai voi max
 	slt $t1,$s4,$s3
	beq $t1,0,_DoiMax
_SoSanh:
	# so sanh toi cuoi mang
	slt $t1,$t0,$s1
	beq $t1,1,_LapTimMax
	j _KetThuc
_DoiMax:
	#Thay doi gia tri max
	add $t1,$s3,$s4	
	sub $s3,$t1,$s3
	j _SoSanh

#cuoi thu tuc
_KetThuc:
 	move $v0,$s3
	#restore cac thanh ghi
	lw $ra,($sp)
	lw $t0,4($sp)
	lw $t1,8($sp)
	lw $s1,12($sp)
	lw $s2,16($sp)
	lw $s3,20($sp)
	lw $s4,24($sp)

	#xoa stack
	addi $sp,$sp,28

	#nhay ve dia chi goi ham $ra
	jr $ra

			
		# Cuoi thu tuc.
		
			# Restore ca'c thanh ghi
			# Xoa stack.
			
			# Return address.

# ---

funct_8: # Sap xep mang tang dan theo Selection sort`.

	# Truyen tham so cho ham.
	# ...
	li $v0,4
	la $a0,funct8_msg
	syscall 
	la $a0,arr_data
	move $a1,$s1
	jal _SelectionSort
	j funct_2
	# Lua chon chuc nang ke tep trong chuong trinh
	j main.choice
	# ---
_SelectionSort:
	#Khai bao kich thuoc stack
	addi $sp,$sp,-36
	#Backup thanh ghi
	sw $ra,($sp)
	sw $a0,4($sp)
	sw $a1,8($sp)
	sw $s0,12($sp)
	sw $s1,16($sp)
	sw $s2,20($sp)
	sw $s3,24($sp)
	sw $s4,28($sp)
	sw $s5,32($sp)
	

	# --
	#than thu tuc
	#Khai bao
	li $t6,2
	slt $t5,$a1,$t6 # so luong phan tu nho hon 2-> ket thúc
	beq $t5,1,_BubbleSort.End
	li $t0,0
	addi $t1,$t0,1
	move $s0,$a0
	addi $t3,$a1,-1
_VongLapThuNhat:
	addi $s2,$s0,4
	lw $s3,($s0)   #t2 chua iMin
	#j _VongLapThuHai
_VongLapThuHai:
	lw $s4,($s2)   #t4 chua a[j]
	slt $t2,$s4,$s3
	beq $t2,1,_TiepTuc
	j _LapJ
_TiepTuc:
	move $s3,$s4	#iMin = a[j]
	lw $s5,($s0)	# lay a[i]
	sw $s5,($s2)
	sw $s4,($s0)
	j _LapJ
_LapJ:
	addi $t1,$t1,1       # j = j+1
	addi $s2,$s2,4       #$s2 = 4$s2
	slt $t2, $t1,$a1     #so sanh j<n    
	beq $t2,1,_VongLapThuHai
	j _LapI
_LapI:
	addi $t0,$t0,1
	addi $t1,$t0,1
	j _TiepTucLap
_TiepTucLap:
	addi $s0,$s0,4
	addi $s2,$s0,4
	slt $t2,$t0,$t3
	beq $t2,1,_VongLapThuNhat
	j _SelectionSort.End
	# Vie^'t pha^`n ca`i dda(.t ha`m ta.i dda^y.
	# ...	
_SelectionSort.End:
	lw $ra,($sp)
	lw $a0,4($sp)
	lw $a1,8($sp)
	lw $s0,12($sp)
	lw $s1,16($sp)
	lw $s2,20($sp)
	lw $s3,24($sp)
	lw $s4,28($sp)
	lw $s5,32($sp)
	addi $sp,$sp,36
	jr $ra
	# ...	
# ---

funct_9: # Sap xep mang giam dan  theo `Bubble sort`.

	# Truye^`n tham so^' cho ha`m.
	# ...
	li $v0,4
	la $a0,funct9_msg
	syscall 
	la $a0,arr_data
	move $a1,$s1
	jal _BubbleSort
	j funct_2
	# ---
	
	# Lua chon chuc nang ke tiep trong chuong trinh	
	j main.choice

	# --
	
	# Vie^'t pha^`n ca`i dda(.t ha`m ta.i dda^y.
_BubbleSort:
	#Khai bao kich thuoc stack
	addi $sp,$sp,-28
	#Backup thanh ghi
	sw $ra,($sp)
	sw $a0,4($sp)
	sw $a1,8($sp)
	sw $s0,12($sp)
	sw $s1,16($sp)
	sw $s2,20($sp)
#than thu tuc
	li $t6,2
	slt $t5,$a1,$t6 # so luong phan tu nho hon 2-> ket thúc
	beq $t5,1,_BubbleSort.End
	move $s0,$a0 #s0 luu dia chi a0
	lw $a0,4($sp) #a0 lay giá tri 
	move $s1,$a0
	li $t0,0 #t0=0
	addi $t1,$a1,-1 #t1=n-1
	addi $t2,$a1,-1 #t2=n-1
	li $t6,4
	mult $t2,$t6
	mflo $t5
	add $s1,$s1,$t5 #s1= ðia chi arr[n-1]
	sw $s1,24($sp) #luu s1 vào stack
_BubbleSort.Lap_1:
	_BubbleSort.Lap_2:
	add $s2,$s1,$zero
	addi $s2,$s2,-4
	lw $t3,($s2) #t3=arr[j-1]
	lw $t4,($s1) #t4=arr[j]
	slt $t5,$t3,$t4 #t3<t4
	beq $t5,1, _BubbleSort.Swap
_BubbleSort.DieuKienLap:
	addi $s1,$s1,-4 #giam s1
	addi $t1,$t1,-1 #giam t1
	slt $t5,$t0,$t1 #so sánh t0,t1
	beq $t5,1,_BubbleSort.Lap_2 #t0<t1 lap 2
	lw $s1,24($sp) #lay s1 luu trong stack
	addi $t1,$a1,-1 #giam t1
	addi $s0,$s0,4 #tang s0
	addi $t0,$t0,1 #tang t0
	slt $t5,$t0,$a1 #kiem tra ðieu kien t0<a1 (n-1)
	beq $t5,1,_BubbleSort.Lap_1
	j _BubbleSort.End
	
_BubbleSort.Swap:
	sw $t4,($s2)
	sw $t3,($s1)
	j _BubbleSort.DieuKienLap
_BubbleSort.End:
	lw $ra,($sp)
	lw $a0,4($sp)
	lw $a1,8($sp)
	lw $s0,12($sp)
	lw $s1,16($sp)
	lw $s2,20($sp)
	addi $sp,$sp,28
	jr $ra
	# ...	

# ---

exit: # Ke^'t thu'c chu+o+ng tri`nh.
	li $v0, 10
	syscall
