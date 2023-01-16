use master
go 
create database colegio

select * from alumnos

select * from examenes2

select l.legajo, e.nota from alumnos l
inner join examenes2 e
on l.legajo = e.legajo
where e.nota >5

select count(nota) from examenes2

select count(legajo)

select e.legajo, a.nombre, a.apellido from alumnos a
inner join examenes2 e on e.legajo = a.legajo
where e.nota > 6  and (where (select count(legajo) as cuenta from examenes where cuenta >2)



select legajo, count  (legajo) from examenes2
where nota < 6 and a_o =2022
group by legajo

select a_o from examenes2