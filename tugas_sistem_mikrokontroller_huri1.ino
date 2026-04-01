// --- KONFIGURASI PIN ---
// Jalur 1 (Kanan Bawah)
int merah1 = 2, kuning1 = 3, hijau1 = 4;
// Jalur 2 (Tengah Bawah)
int merah2 = 5, kuning2 = 6, hijau2 = 7;
// Jalur 3 (Atas)
int merah3 = 8, kuning3 = 9, hijau3 = 10;
// Jalur 4 (Kiri)
int merah4 = 11, kuning4 = 12, hijau4 = 13;

void setup() {
  // Mengatur Pin 2 sampai 13 sebagai OUTPUT menggunakan loop agar ringkas
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  
  matikanSemuaLampu();
}

void loop() {
  // SIKLUS JALUR 1: Hijau -> Kuning (Jalur lain tetap Merah)
  kendaliLampu(hijau1, merah2, merah3, merah4);
  delay(3000); 
  kendaliLampu(kuning1, merah2, merah3, merah4);
  delay(1000); 

  // SIKLUS JALUR 2: Hijau -> Kuning (Jalur lain tetap Merah)
  kendaliLampu(hijau2, merah1, merah3, merah4);
  delay(3000);
  kendaliLampu(kuning2, merah1, merah3, merah4);
  delay(1000);

  // SIKLUS JALUR 3: Hijau -> Kuning (Jalur lain tetap Merah)
  kendaliLampu(hijau3, merah1, merah2, merah4);
  delay(3000);
  kendaliLampu(kuning3, merah1, merah2, merah4);
  delay(1000);

  // SIKLUS JALUR 4: Hijau -> Kuning (Jalur lain tetap Merah)
  kendaliLampu(hijau4, merah1, merah2, merah3);
  delay(3000);
  kendaliLampu(kuning4, merah1, merah2, merah3);
  delay(1000);
}

// FUNGSI PEMBANTU
void kendaliLampu(int aktif, int m_lain1, int m_lain2, int m_lain3) {
  matikanSemuaLampu();
  digitalWrite(aktif, HIGH);   // Nyalakan lampu hijau/kuning di jalur aktif
  digitalWrite(m_lain1, HIGH); // Jalur lain merah
  digitalWrite(m_lain2, HIGH);
  digitalWrite(m_lain3, HIGH);
}

void matikanSemuaLampu() {
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}