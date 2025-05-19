use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    while let Some(Ok(line)) = lines.next() {

        if line.trim().is_empty() {
            continue;
        }

        // let parts: Vec<usize> = line // usize dentro de Vec se comporta como um iterador nos números inteiros.
        //     .split_whitespace()
        //     .map(|s| s.parse().unwrap()) //Usa .unwrap() porque parse retorna Result<usize, _>
        //     .collect(); //Transforma o iterador em um vetor do tipo usize = naturais

        let parts: Vec<usize> = match line //declaração explícita de tipo no parts
            .split_whitespace()
            .map(|s| s.parse::<usize>())
            .collect::<Result<Vec<_>, _>>()
        {
            Ok(nums) => nums,
            Err(e) => {
                eprintln!("Erro ao converter entrada para números: {}", e);
                continue;
            }
        };

        let (linha, coluna, robos, energia) = (parts[0], parts[1], parts[2], parts[3]);

        // MAPA
        let mut mapa = vec![vec![' '; coluna]; linha]; //cria a mateiz já preenchida por ' '.
        let mut teletransportadores = vec![]; //alocação com o tamanho vazio

        for i in 0..linha {
            let linha_mapa = lines.next().unwrap().unwrap();
            for (j, ch) in linha_mapa.chars().enumerate() {
                mapa[i][j] = ch;
                if ch == '*' {
                    teletransportadores.push((i, j));
                }
            }
        }

        // ROBÔS
        for _ in 0..robos {
            let linha_robo = lines.next().unwrap().unwrap();
            let mut parts = linha_robo.split_whitespace();
            let mut x: usize = parts.next().unwrap().parse().unwrap();
            x = x-1;
            let mut y: usize = parts.next().unwrap().parse().unwrap();
            y = y-1;
            let moves = parts.next().unwrap().chars().collect::<Vec<char>>();
            let mut energy = energia;

            println!("Movimentos");
            for mv in moves {
                if energy == 0 {
                    break;
                }

                let (dx, dy) = match mv {
                    'N' => (-1, 0),
                    'S' => (1, 0),
                    'L' => (0, 1),
                    'O' => (0, -1),
                    _ => (0, 0),
                };

                let mut new_x = x as isize + dx;
                let mut new_y = y as isize + dy;


                // if new_x < 0 || new_x >= linha as isize || new_y < 0 || new_y >= coluna as isize {
                //     continue;
                // }
                new_x = if new_x < 0 {linha as isize - 1} else {new_x} ;
                new_x = if new_x >= linha as isize { 0isize } else {new_x} ;
                new_y = if new_y < 0 {coluna as isize - 1} else {new_y} ;
                new_y = if new_y >= coluna as isize { 0isize } else {new_y} ;

                let (nx, ny) = (new_x as usize, new_y as usize);
                let saida_celula = mapa[x][y];
                let nova_celula = mapa[nx][ny];

                if nova_celula == '#' {
                    continue; // obstáculo
                }

                let cost = if nova_celula == '@' || saida_celula == '@'  { 2 } else { 1 };

                if energy < cost {
                    break;
                }

                if x == nx && y == ny {continue} else {
                    x = nx;
                    y = ny;
                    energy -= cost;
                }

                if nova_celula == '*' && teletransportadores.len() > 1 {
                    for &(tx, ty) in &teletransportadores {
                        if tx != x || ty != y {
                            x = tx;
                            y = ty;
                            break;
                        }
                    }
                }
                println!("({}, {}) e energia={}", x+1, y+1, energy);
            }

            println!("Resposta> ({}, {}) e energia={}", x+1, y+1, energy);
        }
    }
}