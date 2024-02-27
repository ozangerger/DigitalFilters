from matplotlib import pyplot as plt
import pandas as pd


def main():
    df = pd.read_csv('data.csv')
    fig1, ax1 = plt.subplots(tight_layout=True)
    ax1.plot(df['time'], df['hpf_raw_data'], df['time'], df['hpf_data'])
    ax1.set_xlabel('Time [s]')
    ax1.set_ylabel('Data')
    ax1.set_title(r'High-pass Filter', fontsize=16)
    fig1.savefig('hpf_plot')

    fig2, ax2 = plt.subplots(tight_layout=True)
    ax2.plot(df['time'], df['lpf_raw_data'], df['time'], df['lpf_data'])
    ax2.set_xlabel('Time [s]')
    ax2.set_ylabel('Data')
    ax2.set_title(r'Low-pass Filter', fontsize=16)
    fig2.savefig('lpf_plot')

    fig3, ax3 = plt.subplots(tight_layout=True)
    ax3.plot(df['time'], df['nf_raw_data'], df['time'], df['nf_data'])
    ax3.set_xlabel('Time [s]')
    ax3.set_ylabel('Data')
    ax3.set_title(r'Notch Filter', fontsize=16)
    fig3.savefig('nf_plot')

    fig4, ax4 = plt.subplots(tight_layout=True)
    ax4.plot(df['time'], df['hf_raw_data'], df['time'], df['hf_data'])
    ax4.set_xlabel('Time [s]')
    ax4.set_ylabel('Data')
    ax4.set_title(r'Hanning Filter', fontsize=16)
    fig4.savefig('hf_plot')


if __name__ == '__main__':
    main()
