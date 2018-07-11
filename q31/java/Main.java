public class Main{
    public static void main(String[] args) {
        new Main().start();
    }

    final int N = 8;
    final int USED = 1;
    final int UN_USED = 0;
    final int NONE = -1;
    final int YOKO = 2;
    final int SHITA = 3;

    int answer = 0;

    Point points[][] = new Point[N+1][N+1];
    Point getPoint(int r, int c){
        return points[r][c];
    }
    void start(){
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                points[i][j] = new Point(i,j);
            }
        }

        points[0][0].move(false);

        System.out.println(answer);
    }

    class Point{
        int r,c;
        int edge_migi;
        int edge_shita;
        int edge_ue;
        int edge_hidari;
        Point(int r, int c){
            this.r = r;
            this.c = c;
            if(this.c != N) edge_migi = UN_USED;
            else edge_migi = NONE;
            if(this.r != N) edge_shita = UN_USED;
            else edge_shita = NONE;
            if(this.r != 0) edge_ue = UN_USED;
            else edge_ue = NONE;
            if(this.c != 0) edge_hidari = UN_USED;
            else edge_hidari = NONE;
        }

        void set_road(int dir, boolean unset){
            switch (dir) {
                case YOKO:
                    if(!unset)edge_hidari = USED;
                    else edge_hidari = UN_USED;
                    break;
                case SHITA:
                    if(!unset) edge_ue = USED;
                    else edge_ue = UN_USED;
                    break;
            }
        }
        void move(boolean is_return_path){
            // System.out.print("[" + r + ", " + c + "] => ");
            if(is_return_path && this.r == 0 && this.c == 0){
                answer++;
                // System.out.println("find");
                return;
            }
            if(!is_return_path && this.r == N && this.c == N){
                is_return_path = true;
                this.move(is_return_path);
            }else{
                if(!is_return_path){
                    if(edge_migi == UN_USED){
                        edge_migi = USED;
                        Point next = points[r][c+1];
                        next.set_road(YOKO, false);
                        next.move(is_return_path);
                        next.set_road(YOKO, true);
                        edge_migi = UN_USED;
                    }
                    if(edge_shita == UN_USED){
                        edge_shita = USED;
                        Point next = points[r + 1][c];
                        next.set_road(SHITA, false);
                        next.move(is_return_path);
                        next.set_road(SHITA, true);
                        edge_shita = UN_USED;
                    }
                }else{
                    if(edge_hidari == UN_USED){
                        edge_hidari = USED;
                        points[r][c - 1].move(is_return_path);
                        edge_hidari = UN_USED;
                    }
                    if(edge_ue == UN_USED){
                        edge_ue = USED;
                        points[r - 1][c].move(is_return_path);
                        edge_ue = UN_USED;
                    }
                }
            }
        }
    }
}
